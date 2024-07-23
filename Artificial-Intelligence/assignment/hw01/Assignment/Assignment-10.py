import numpy as np
import tensorflow as tf
from keras.datasets import mnist
from keras.models import Sequential
from keras.layers import Dense
from keras.optimizers import SGD,Adam,Adagrad,RMSprop
from sklearn.model_selection import KFold
import matplotlib.pyplot as plt

# fashion MNIST를 읽고 신경망에 입력할 형태로 변환
(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train = x_train.reshape(60000,784)
x_test = x_test.reshape(10000,784)
x_train=x_train.astype(np.float32)/255.0
x_test=x_test.astype(np.float32)/255.0
y_train=tf.keras.utils.to_categorical(y_train,10)
y_test=tf.keras.utils.to_categorical(y_test,10)

# 신경망 구조 설정
n_input=784
n_hidden1=1024
n_hidden2=512
n_hidden3=512
n_hidden4=512
n_output=10

# 하이퍼 매개변수 설정
batch_siz=256
n_epoch=20
k=5 # 5-겹

# 모델을 설계해주는 함수(모델을 나타내는 객체 model을 반환)
def build_model():
    model=Sequential()
    model.add(Dense(units=n_hidden1,activation='relu',input_shape=(n_input,)))
    model.add(Dense(units=n_hidden2,activation='relu'))
    model.add(Dense(units=n_hidden3,activation='relu'))
    model.add(Dense(units=n_hidden4,activation='relu'))
    model.add(Dense(units=n_output,activation='softmax'))
    return model

# 교차 검증을 해주는 함수(서로 다른 옵티마이저(opt)에 대해)
def cross_validation(opt):
    accuracy=[]
    for train_index,val_index in KFold(k).split(x_train):
        xtrain,xval=x_train[train_index],x_train[val_index]
        ytrain,yval=y_train[train_index],y_train[val_index]
        dmlp=build_model()
        dmlp.compile(loss='categorical_crossentropy',optimizer=opt,metrics=['accuracy'])
        dmlp.fit(xtrain,ytrain,batch_size=batch_siz,epochs=n_epoch,verbose=0)
        accuracy.append(dmlp.evaluate(xval,yval,verbose=0)[1])
    return accuracy

# 옵티마이저 4개에 대해 교차 검증을 실행
acc_sgd=cross_validation(SGD(learning_rate=0.001))
acc_adam=cross_validation(Adam(learning_rate=0.001))
acc_adagrad=cross_validation(Adagrad(learning_rate=0.001))
acc_rmsprop=cross_validation(RMSprop(learning_rate=0.001))

# 옵티마이저 4개의 정확률을 비교
print("SGD:",np.array(acc_sgd).mean())
print("Adam:",np.array(acc_adam).mean())
print("Adagrad:",np.array(acc_adagrad).mean())
print("RMSprop:",np.array(acc_rmsprop).mean())



# 네 옵티마이저의 정확률을 박스플롯으로 비교
# plt.boxplot([acc_sgd,acc_adam,acc_adagrad,acc_rmsprop],labels=["SGD","Adam","Adagrad","RMSprop"])
# plt.grid()

opts=[np.array(acc_sgd).mean(),np.array(acc_adam).mean(),np.array(acc_adagrad).mean(),np.array(acc_rmsprop).mean()]
idx=opts.index(max(opts))

#교차 검증을 해주는 함수(서로 다른 옵티마이저(opt)에 대해)
def cross_validation2(opt,batch_siz):
    accuracy=[]
    for train_index,val_index in KFold(k).split(x_train):
        xtrain,xval=x_train[train_index],x_train[val_index]
        ytrain,yval=y_train[train_index],y_train[val_index]
        dmlp=build_model()
        dmlp.compile(loss='categorical_crossentropy',optimizer=opt,metrics=['accuracy'])
        dmlp.fit(xtrain,ytrain,batch_size=batch_siz,epochs=n_epoch,verbose=0)
        accuracy.append(dmlp.evaluate(xval,yval,verbose=0)[1])
    return accuracy

select=Adam(learning_rate=0.001)
name="Adam"
print()
if idx==0:
    print("선택된 옵티마이저 SGD")
    name="SGD"
    select=SGD(learning_rate=0.001)
    
elif idx==1:
    print("선택된 옵티마이저 Adam")
    name="Adam"
    select=Adam(learning_rate=0.001)

elif idx==2:
    print("선택된 옵티마이저 Adagrad")
    name="Adagrad"
    select=Adagrad(learning_rate=0.001)
else:
    print("선택된 옵티마이저 RMSprop")
    name="RMSprop"
    select=RMSprop(learning_rate=0.001)

print(select)
print(name)
acc_bat64=cross_validation2(select,64)
acc_bat128=cross_validation2(select,128)
acc_bat256=cross_validation2(select,256)
acc_bat512=cross_validation2(select,512)
acc_bat1024=cross_validation2(select,1024)

print("BatchSize_64:",np.array(acc_bat64).mean())
print("BatchSize_128:",np.array(acc_bat128).mean())
print("BatchSize_256:",np.array(acc_bat256).mean())
print("BatchSize_512:",np.array(acc_bat512).mean())
print("BatchSize_1024:",np.array(acc_bat1024).mean())

# plt.boxplot([acc_bat64,acc_bat128,acc_bat256,acc_bat512,acc_bat1024],labels=["BatchSize_64","BatchSize_128","BatchSize_256","BatchSize_512","BatchSize_1024"])
# plt.grid()
def cross_validation3(opt,batch_siz,n_epoch):
    accuracy=[]
    for train_index,val_index in KFold(k).split(x_train):
        xtrain,xval=x_train[train_index],x_train[val_index]
        ytrain,yval=y_train[train_index],y_train[val_index]
        dmlp=build_model()
        dmlp.compile(loss='categorical_crossentropy',optimizer=opt,metrics=['accuracy'])
        dmlp.fit(xtrain,ytrain,batch_size=batch_siz,epochs=n_epoch,verbose=0)
        accuracy.append(dmlp.evaluate(xval,yval,verbose=0)[1])
    return accuracy

batches=[np.array(acc_bat64).mean(),np.array(acc_bat128).mean(),np.array(acc_bat256).mean(),np.array(acc_bat512).mean(),np.array(acc_bat1024).mean()]
idx=batches.index(max(batches))

size=256
print()
if idx==0:
    print("선택된 배치 사이즈 64")
    size=64
elif idx==1:
    print("선택된 배치 사이즈 128")
    size=128
elif idx==2:
    print("선택된 배치 사이즈 256")
    size=256
elif idx==3:
    print("선택된 배치 사이즈 512")
    size=512
else:
     print("선택된 배치 사이즈 1024")
     size=1024
#print(size)

acc_ep20=cross_validation3(select,size,20)
acc_ep40=cross_validation3(select,size,40)
acc_ep60=cross_validation3(select,size,60)
acc_ep80=cross_validation3(select,size,80)
acc_ep100=cross_validation3(select,size,100)

print("epoch_20:",np.array(acc_ep20).mean())
print("epoch_40:",np.array(acc_ep40).mean())
print("epoch_60:",np.array(acc_ep60).mean())
print("epoch_80:",np.array(acc_ep80).mean())
print("epoch_100:",np.array(acc_ep100).mean())

epos=[np.array(acc_ep20).mean(),np.array(acc_ep40).mean(),np.array(acc_ep60).mean(),np.array(acc_ep80).mean(),np.array(acc_ep100).mean()]
idx=epos.index(max(epos))

epo=20
print()
if idx==0:
    print("선택된 epoch 20")
    epo=20
elif idx==1:
    print("선택된 epoch 40")
    epo=40
elif idx==2:
    print("선택된 epoch 60")
    epo=60
elif idx==3:
    print("선택된 epoch 80")
    epo=80
else:
    print("선택된 epoch 100")
    epo=100
#print(epo)
print("사용된 하이퍼 매개변수" )
print("학습률: %f 옵티마이저: %s, 배치사이즈: %d, epoch: %d"%(0.001,name,size,epo))
print("최적의 정확률: ",epos[idx]*100,"%")
