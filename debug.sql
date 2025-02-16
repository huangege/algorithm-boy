select second_stand_food,----'二级标准菜'
       poi_brand_name,---'品牌'
       case when id>=2 then '复购'
            else '未复购'
             end as `用户类型`,
       count(distinct user_id),---'人数'
       sum(total) ---'核心用户GMV'
       from(
        select a.dt,
               b.second_stand_food,
               a.poi_brand_name,
               a.user_id,
               count(distinct a.id) as id,
               sum(a.`total`) as total from(
                select b.dt,
                       a.wm_sku_id,
                       b.user_id,
                       b.id,
                       b.poi_biz_type_id, 
                       b.poi_brand_name,
                       a.sku_actual_price*a.cnt as `total`
                  from mart_waimai.aggr_food_ord_act_detail_sd a
                 inner join (
                  select * from
                  mart_waimai.topic_ord_info_d 
                  where b.poi_biz_type_id=1
                 ) b
                    on a.wm_order_id=b.id
                 	and a.dt =b.dt
                 inner join(
                        select 
                               a.mt_user_id from(
                                SELECT
                                       mt_user_id
                                  FROM mart_uzen.app_user_wealth_strat_info_v2_week_all
                                 WHERE partition_date in('2024-12-25')
                                   AND score_level in ('L3','L4','L5')
                                 group by 1
                               )a
                         INNER JOIN(
                                select distinct user_id
                                  from mart_waimai.dim_s_usr_attr_snapshot
                                 where dt ='20241225'
                           AND disc_sensitivity_id in (3,4,5)
                               )b
                            on a.mt_user_id=b.user_id
                         GROUP BY 1
                       )c
                    on  b.user_id=c.mt_user_id
                 where a.dt between $$begindatekey and $$enddatekey and b.second_city_name in('西安')
                 group by 1,
                          2,
                          3,
                          4,
                          5,
                          6
               )a
          left join(
                select 
                       wm_food_id,
                       second_stand_food
                  from mart_waimaigrowth.topic_food_sku_main_category_stand_food_prediction_with_combo_info_dd
                 where dt ='20250105' and first_cate_name in('饮品')
                 group by 1,
                          2
               )b
            on  a.wm_sku_id=b.wm_food_id
         GROUP BY 1,
                  2,
                  3,
                  4
       )
 where second_stand_food is not null
 GROUP BY 1,
          2,
          3