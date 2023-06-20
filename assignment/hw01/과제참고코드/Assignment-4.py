from sklearn import datasets
from sklearn import svm, tree
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score, train_test_split
import numpy as np

digit=datasets.load_digits()
x_train,x_test,y_train,y_test=train_test_split(digit.data,digit.target,train_size=0.6) # 40%를 테스트 집합으로 함

################
# 본인 코드 작성
################
