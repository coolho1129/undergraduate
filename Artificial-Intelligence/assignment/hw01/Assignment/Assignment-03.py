from sklearn import datasets

d=datasets.load_iris() # iris 데이터셋을 읽고
print(d.DESCR) # 내용을 출력
for i in range(0,len(d.data)): # 샘플을 순서대로 출력
    print(i+1,d.data[i],d.target[i])
    
from sklearn import svm

s=svm.SVC(gamma=0.1,C=10) # svm 분류 모델 SVC 객체 생성하고
s.fit(d.data,d.target) # iris 데이터로 학습

res_SVM=s.predict(d.data)
print("SVM: 샘플의 부류는", res_SVM)

correct=[i for i in range(len(res_SVM)) if res_SVM[i]==d.target[i]]
accuracy=len(correct)/len(res_SVM)
print("SVM 정확률=",accuracy*100, "%")

################
# 본인 코드 작성
################
from sklearn import tree

t=tree.DecisionTreeClassifier() 
t=t.fit(d.data,d.target)

res_DTC=t.predict(d.data)
print("DTC: 샘플의 부류는", res_DTC)

correct=[i for i in range(len(res_DTC)) if res_DTC[i]==d.target[i]]
accuracy=len(correct)/len(res_DTC)
print("DTC 정확률=",accuracy*100, "%")
