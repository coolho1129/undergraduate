import numpy as np
import tensorflow as tf
from keras.datasets import mnist
from keras.models import Sequential
from keras.layers import Dense
from keras.optimizers import Adam
import matplotlib.pyplot as plt

# MNIST 읽어 와서 신경망에 입력할 형태로 변환
(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train = x_train.reshape(60000,784) # 텐서 모양 변환
x_test = x_test.reshape(10000,784)
x_train=x_train.astype(np.float32)/255.0 # ndarray로 변환
x_test=x_test.astype(np.float32)/255.0
y_train=tf.keras.utils.to_categorical(y_train,10) # 원핫 코드로 변환
y_test=tf.keras.utils.to_categorical(y_test,10)

# 신경망 구조 설정
n_input=784
n_hidden1=1024
n_hidden2=512
n_hidden3=512
n_hidden4=512
n_output=10



def bulid(name,color):
        
        kinit=name
        # 신경망 구조 설계
        mlp=Sequential()
        mlp.add(Dense(units=n_hidden1,activation='tanh',input_shape=(n_input,),kernel_initializer=kinit,bias_initializer='zeros'))
        mlp.add(Dense(units=n_hidden2,activation='tanh',kernel_initializer=kinit,bias_initializer='zeros'))
        mlp.add(Dense(units=n_hidden3,activation='tanh',kernel_initializer=kinit,bias_initializer='zeros'))
        mlp.add(Dense(units=n_hidden4,activation='tanh',kernel_initializer=kinit,bias_initializer='zeros'))
        mlp.add(Dense(units=n_output,activation='tanh',kernel_initializer=kinit,bias_initializer='zeros'))

    

        # 신경망 학습
        mlp.compile(loss='mean_squared_error',optimizer=Adam(learning_rate=0.001),metrics=['accuracy'])
        hist=mlp.fit(x_train,y_train,batch_size=128,epochs=30,validation_data=(x_test,y_test),verbose=0)
     

        # 신경망의 정확률 측정
        res=mlp.evaluate(x_test,y_test,verbose=0)
        print(name)
        print("정확률은",res[1]*100,"%")
        
        # 정확률 곡선
        plt.plot(hist.history['accuracy'],color[0])
        plt.plot(hist.history['val_accuracy'],color[1])
   
        plt.title('Model accuracy')
        plt.ylabel('Accuracy')
        plt.xlabel('Epoch')
        plt.legend([name,'val_' + name], loc='best')
        plt.grid()
        plt.show()

        # 손실 함수 곡선
        plt.plot(hist.history['loss'],color[0])
        plt.plot(hist.history['val_loss'],color[1])
       
        plt.title('Model loss')
        plt.ylabel('Loss')
        plt.xlabel('Epoch')
        plt.legend([name,'val_' + name], loc='best')
        plt.grid()
        plt.show()

        


hists=[]
colors=[("r",'r--'),("g","g--"),("b","b--")]
hists.append(bulid('glorot_uniform',colors[0]))
hists.append(bulid('glorot_normal',colors[1]))
hists.append(bulid('random_normal',colors[2]))


    