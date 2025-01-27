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

df = pd.read_excel(multiple_data_path, sheet_name='铌铁矿')



def data_process():
    all_data_training = open(all_data_training_path, 'w')
    zjs_data_raw = open(zjs_raw_path, 'r')
    lhs_data_raw = open(lhs_raw_path, 'r')

    data_training = read_and_tranverse(zjs_data_raw, 0)
    data_training = data_training + read_and_tranverse(lhs_data_raw, 1, False)

    for i in data_training:
        all_data_training.write(i)

    all_data_training.close()

def read_and_tranverse(data_row, label=0, header=True):
    data_training = []
    head_label = 'label'
    lines = data_row.readlines()
    head_raw = lines[0].replace('\r', '').replace('\n', '')
    head1 = head_raw.replace(',', '-K,') + '-K'
    head2 = head_raw.replace(',', '-L,') + '-L'
    head3 = head_raw.replace(',', '-M,') + '-M'
    head_training = head_label + ',' + head1 + ',' + head2 + ',' + head3 + '\n'
    if header:
        data_training.append(head_training)
    lines = lines[1:]

    for i in range(len(lines)):
        lines[i] = lines[i].replace('\r', '').replace('\n', '')

    num_samples = len(lines) // 3

    for i in range(num_samples):
        newline = str(label) + ',' + lines[i * 3] + ',' +  lines[i * 3 + 1]  + ',' +  lines[i * 3 + 2] + '\n'
        data_training.append(newline)

    return data_training

def training_gbdt():
    training_data = pd.read_csv(all_data_training_path)
    print(len(training_data))
    # split training and testing
    training_set = training_data.sample(frac=0.5)
    testing_set = training_data.drop(training_set.index)
    y_train = training_set['label']
    y_test = testing_set['label']
    X_train = training_set.drop('label', axis=1)
    X_test = testing_set.drop('label', axis=1)
    print(y_train)
    gradient_booster = GradientBoostingClassifier(learning_rate=0.1)
    gradient_booster.fit(X_train,y_train)
    print(gradient_booster.predict(X_test))
    print(y_test)
    print(gradient_booster.predict(X_test))
    print(y_test)
    print(classification_report(y_test,gradient_booster.predict(X_test)))
    
    print('输出特征重要性：')
    fi = gradient_booster.feature_importances_
    feature_cols = list(training_data.columns)[1:]

    fi = list(zip(feature_cols, fi))
    fi = sorted(fi, key = lambda x:-x[1])

    for i in range(len(fi)):
        print(fi[i][0], ': ', fi[i][1])



if __name__ == "__main__":
    training_gbdt()











