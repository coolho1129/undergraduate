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
select=[]
s=svm.SVC(gamma=0.001)
s_accuracies=cross_val_score(s,x_train,y_train,cv=5)
print("SVM 정확률 집합")
print(s_accuracies)
print("SVM 정확률(평균)=%0.3f"%(s_accuracies.mean()*100))
select.append(s_accuracies.mean()*100)

t=tree.DecisionTreeClassifier()
t_accuracies=cross_val_score(t,x_train,y_train,cv=5)
print("DTC 정확률 집합")
print(t_accuracies)
print("DTC정확률(평균)=%0.3f"%(t_accuracies.mean()*100),"%")
select.append(t_accuracies.mean()*100)

r=RandomForestClassifier(max_depth=2, random_state=0)
r_accuracies=cross_val_score(r,x_train,y_train,cv=5)
print("RFC 정확률 집합")
print(r_accuracies)
print("RFC 정확률(평균)=%0.3f"%(r_accuracies.mean()*100),"%")
select.append(r_accuracies.mean()*100)

idx=select.index(max(select))



if idx==0:
    print("선택된 모델 SVM")
    s.fit(x_test,y_test) 
    res=s.predict(x_test)
    
elif idx==1:
    print("선택된 모델 DTC")
    t.fit(x_test,y_test) 
    res=t.predict(x_test)

else:
    print("선택된 모델 RFC")
    r.fit(x_test,y_test) 
    res=r.predict(x_test)
    
    
correct=[i for i in range(len(res)) if res[i]==y_test[i]]
accuracy=len(correct)/len(res)
print("정확률=",accuracy*100, "%")
