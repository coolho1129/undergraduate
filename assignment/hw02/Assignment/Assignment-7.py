import numpy as np
from tensorflow.keras.datasets import imdb
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense,LSTM,Embedding
from tensorflow.keras import preprocessing
from tensorflow.keras.callbacks import EarlyStopping
from sklearn.model_selection import KFold

dic_siz=10000 # 사전의 크기(사전에 있는 단어 개수)
sample_siz=512 # 샘플의 크기

# tensorflow가 제공하는 간소한 버전의 IMDB 읽기
(x_train,y_train),(x_test,y_test)=imdb.load_data(num_words=dic_siz)

embed_space_dim=16 # 16차원의 임베딩 공간

x_train=preprocessing.sequence.pad_sequences(x_train,maxlen=sample_siz)
x_test=preprocessing.sequence.pad_sequences(x_test,maxlen=sample_siz)

early=EarlyStopping(monitor='val_accuracy',patience=5,restore_best_weights=True)

def build_model():
    model=Sequential()
    model.add(Embedding(input_dim=dic_siz,output_dim=embed_space_dim,input_length=sample_siz))
    model.add(LSTM(units=32))
    model.add(Dense(1,activation='sigmoid'))
    
    return model 

k=3
accuracy=[]
for train_index,val_index in KFold(k).split(x_train):
    xtrain,xval=x_train[train_index],x_train[val_index]
    ytrain,yval=y_train[train_index],y_train[val_index]
    # 신경망 모델의 설계와 학습(LSTM 층 포함)
    embed=build_model()
    embed.compile(loss='binary_crossentropy',optimizer='Adam',metrics=['accuracy'])
    embed.fit(x_train,y_train,epochs=5,batch_size=64,validation_split=0.2,verbose=2,callbacks=[early])

    # 모델 평가
    accuracy.append(embed.evaluate(xval,yval,verbose=0)[1])


print(accuracy)
print("정확률(평균): ",np.array(accuracy).mean())