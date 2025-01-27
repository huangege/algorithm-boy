with users as (
select 
    user_id,
    physics_pepole_subdivision_name,
    case when income_level_id in (1,2) and disc_sensitivity_id in (3,4,5) then 1 else 0 end as key_tag-- 优惠敏感度ID、月收入水平ID
  from mart_waimai.dim_s_usr_attr_snapshot
 where dt = $$enddatekey
group by 1,2,3
),
-- 核心用户新口径:购买力等级
scr as (
      SELECT 
          scr.user_id,
          scr.consumption_score_level `购买力`,
          physics_pepole_subdivision_name
          -- case when consumption_score_level in ('L3','L4','L5') then 1 else 0 end as `是否属于L3,L4,L5`,
          -- case when consumption_score_level in ('L4','L5') then 1 else 0 end as `是否属于L4,L5`
          FROM mart_business_middle_group.sqs_core_user scr
      JOIN(
          select distinct
            user_id,
            physics_pepole_subdivision_name
            from mart_waimai.dim_s_usr_attr_snapshot
           where dt='$$enddatekey'
             AND disc_sensitivity_id in (3,4,5)
         )c on scr.user_id=c.user_id
       WHERE scr.dt = $$enddatekey{-1d}
         AND consumption_score_level in ('L1','L2','L3','L4','L5')-- 购买力L1,L2,L3,L4,L5
  group by 1,2,3
),
bzc as (
select
sku_id,
max(stand_food_name) as stand_food
from mart_cdcrm.topic_must_sell_food_info_d
where dt BETWEEN $$begindatekey and $$enddatekey
and stand_food_name is not null
and stand_food_name in ('莴笋','韭菜盒子','韭菜炒蛋','笋','荠菜鲜肉馄饨','青团','荠菜鲜肉水饺','荠菜肉水饺','蕨菜','豆沙青团','蛋黄肉松青团','荠菜馄饨','荠菜鸡蛋包','香椿炒鸡蛋','韭菜炒香干','莴笋炒蛋','油焖笋','荠菜包','荠菜肉包','荠菜肉蒸饺','咸蛋黄肉松青团','腌笃鲜','艾草青团','黑芝麻青团','荠菜生煎','蕨菜炒腊肉','香椿煎蛋','蕨菜炒肉','咸蛋黄青团','炒蕨菜','马兰头青团','芝麻青团','青团子','芋泥青团','芒果青团','肉末蕨菜','香椿鸡蛋','马兰香干青团','茶香笋鸡','蒜苗炒蚕豆','奶香芋泥青团','鲜笋回锅肉','蒜苗蚕豆','马兰头','野蕨菜炒肉','炒马兰头','酒糟炒蕨菜','腌笃鲜青团') 
group by 1)
-- dp和sqs要分开跑，前三张表做引用
select
substr(a.dt, 1, 6),
a.primary_second_tag_name,
a.primary_third_tag_name,
bzc.stand_food,
-- ord.wm_food_name,
scr.`购买力`,
physics_pepole_subdivision_name,
count (distinct a.user_id) `用户数`,
sum(wm_food_price)`货架GMV`,
count(distinct wm_order_id)`货架订单`
from (
      select
       x.dt,
  x.second_city_name,
  x.primary_second_tag_name,
       x.primary_third_tag_name,
  x.id,
  x.poi_dt_aor_id,
  x.poi_dt_aor_name,
     x.wm_poi_id,
       x.poi_name,
  x.user_id
      from mart_waimai.topic_ord_info_d x
      where x.dt BETWEEN $$begindatekey and $$enddatekey
 -- and second_city_name = ('长沙')
       -- and primary_second_tag_name in ('中式正餐')
        -- and poi_type in (3)
  and is_arrange=1
  and biz_type_id in (1,2)
 group by 1,2,3,4,5,6,7,8,9,10
) a
left join (
select
dt,
wm_food_id,
wm_food_price,
wm_order_id,
  wm_food_name
FROM mart_waimai.fact_ord_order_detail a
where a.dt BETWEEN $$begindatekey and $$enddatekey
group by 1,2,3,4,5) ord on a.id =ord.wm_order_id and a.dt =ord.dt -- 订单明细表
left join bzc on ord.wm_food_id = bzc.sku_id -- 标准菜
left join scr on a.user_id = scr.user_id 
group by 1,2,3,4,5,6
