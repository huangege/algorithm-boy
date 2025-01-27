# coding: utf-8
import lightgbm
import pandas as pd
from sklearn.metrics import mean_squared_error
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.metrics import classification_report

label_dict = {
    '包头矿': 1,
    'CeNd易解石': 2,
    '金红石': 3,
    '铌铁金红石': 4,
    '铌钙矿': 5,
    '铌铁矿': 6,
    '烧绿石': 7,
    '磷灰石': 8,
    '重晶石': 9,
}

multiple_data_path = '/Users/duruihuan/Projects/algorithm-boy/data_2501/六种典型.xlsx'
feature_col_prefix_path = '/Users/duruihuan/Projects/algorithm-boy/data_2501/feature_col_prefix.csv'

def multiple_data_process():
    data_training = []
    feature_col_prefix = pd.read_csv(feature_col_prefix_path)
    feature_col_prefix_list = feature_col_prefix['col_prefix'].tolist()
    feature_cols = ['label']
    for i in feature_col_prefix_list:
        feature_cols.append(i + '-K')
        feature_cols.append(i + '-L')
        feature_cols.append(i + '-M')

    for label in label_dict:
        if label in ['磷灰石', '重晶石']:
            continue
        df = pd.read_excel(multiple_data_path, sheet_name=label)
        label_index = label_dict[label]
        df = df.fillna(0.0)
        rows, columns = df.shape
        if columns % 4 != 0:
            print(f'Wrong data: {label}')
            return None
        num_data = columns // 4
        for i in range(num_data):
            feature_line = [label_index]
            for j in range(1, 85):
                feature_line.append(df.iloc[j, i * 4 + 1])
                feature_line.append(df.iloc[j, i * 4 + 2])
                feature_line.append(df.iloc[j, i * 4 + 3])
            data_training.append(feature_line)
        
    training_df = pd.DataFrame(data_training, columns=feature_cols)

    return training_df


def training_gbdt(training_data, shuffle=False):
    print(len(training_data))
    if shuffle:
         training_data = training_data.sample(frac=1.0)
    # split training and testing
    training_set = training_data.sample(frac=0.5)
    testing_set = training_data.drop(training_set.index)
    y_train = training_set['label']
    y_test = testing_set['label']
    X_train = training_set.drop('label', axis=1)
    X_test = testing_set.drop('label', axis=1)
    print('Trainingset labels:')
    print(y_train.tolist())
    gradient_booster = GradientBoostingClassifier(learning_rate=0.1)
    gradient_booster.fit(X_train,y_train)
    print('Prediction results of testset:')
    print(list(gradient_booster.predict(X_test)))
    print('True results of testset:')
    print(y_test.tolist())
    print(classification_report(y_test,gradient_booster.predict(X_test)))
    
    print('Feature importance:')
    fi = gradient_booster.feature_importances_
    feature_cols = list(training_data.columns)[1:]

    fi = list(zip(feature_cols, fi))
    fi = sorted(fi, key = lambda x:-x[1])

    for i in range(len(fi)):
        print(fi[i][0], ': ', fi[i][1])


def train_multiple():
    training_data = multiple_data_process()
    # train a model for each stone
    for label in label_dict:
        if label in ['磷灰石', '重晶石']:
                    continue
        print('================================')
        print(f'Training model for {label}.')
        label_index = label_dict[label]
        training_data_cur = training_data.copy()
        training_data_cur['label'] = (training_data_cur['label'] == label_index).astype(int)
        training_gbdt(training_data_cur, shuffle=True)
        print('================================')



if __name__ == "__main__":
    train_multiple()











