from sklearn.datasets import fetch_openml
from sklearn.neural_network import MLPClassifier
import matplotlib.pyplot as plt
import numpy as np

# MNIST 데이터셋을 읽고 훈련 집합과 테스트 집합으로 분할
mnist=fetch_openml('mnist_784')
mnist.data=mnist.data/255.0
x_train=mnist.data[:60000]; x_test=mnist.data[60000:]
y_train=np.int16(mnist.target[:60000]); y_test=np.int16(mnist.target[60000:])

################
# 본인 코드 작성
################


# print("(은닉층 1개)테스트 집합에 대한 정확률은", ~~~ , "%입니다.")
# print("(은닉층 2개)테스트 집합에 대한 정확률은", ~~~ , "%입니다.")
# print("(은닉층 3개)테스트 집합에 대한 정확률은", ~~~ , "%입니다.")
# print("(은닉층 4개)테스트 집합에 대한 정확률은", ~~~ , "%입니다.")
# print("(은닉층 5개)테스트 집합에 대한 정확률은", ~~~ , "%입니다.")
