#!/usr/bin/env python
# coding: utf-8

# Python ≥3.5 is required
import sys
assert sys.version_info >= (3, 5)

# Scikit-Learn ≥0.20 is required
import sklearn
assert sklearn.__version__ >= "0.20"

# Common imports
import numpy as np
import os
import warnings
warnings.filterwarnings('ignore')

# to make this notebook's output stable across runs
np.random.seed(42)

from sklearn.model_selection import train_test_split
from sklearn.datasets import make_moons
import matplotlib.pyplot as plt

X, y = make_moons(n_samples=3000, noise=0.2, random_state=42)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.5, random_state=42)

print("Trainset: {}, Testset: {}".format(X_train.shape, y_train.shape))

plt.scatter(X_train[:, 0], X_train[:, 1], marker='.', c=y_train, s=100,
            edgecolor="k", linewidth=1)
plt.xlabel("$X_1$")
plt.ylabel("$X_2$")
plt.show()

plt.scatter(X_test[:, 0], X_test[:, 1], marker='.', c=y_test, s=100,
            edgecolor="k", linewidth=1)
plt.xlabel("$X_1$")
plt.ylabel("$X_2$")
plt.show()

'''
plt.scatter(X_train[:, 1], X_train[:, 2], marker='.', c=y_train, s=100,
            edgecolor="k", linewidth=1)
plt.xlabel("$X_1$")
plt.ylabel("$X_2$")
plt.show()

plt.scatter(X_train[:, 0], X_train[:, 2], marker='.', c=y_train, s=100,
            edgecolor="k", linewidth=1)
plt.xlabel("$X_1$")
plt.ylabel("$X_2$")
plt.show()
'''

from sklearn.linear_model import LogisticRegression
from sklearn.linear_model import SGDClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import SVC
from sklearn.ensemble import VotingClassifier
from sklearn.ensemble import BaggingClassifier
from sklearn.ensemble import AdaBoostClassifier
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import PolynomialFeatures
from sklearn.preprocessing import StandardScaler
from sklearn.svm import LinearSVC

def get_models(r_state=42, n_est=50, lr=0.1):
    models = dict()
    models['log'] =  LogisticRegression(solver="lbfgs", random_state=42)
    models['sgd']= SGDClassifier(loss="hinge", learning_rate="constant", 
                                 eta0=0.001, max_iter=10000, tol=1e-3, 
                                 random_state=r_state)
    models['dt'] = DecisionTreeClassifier(random_state=r_state)
    models['rf'] = RandomForestClassifier(
                                          random_state=r_state)
    models['lsvm'] = SVC(kernel="linear", random_state=r_state)
    models['polsvm'] = Pipeline([
        ("poly_features", PolynomialFeatures(degree=10)),
        ("scaler", StandardScaler()),
        ("svm_clf", LinearSVC(C=10, loss="hinge", random_state=42))
    ])
    models['vote'] = VotingClassifier(
        estimators=[('log', models['log']), 
                    ('sgd', models['sgd']), 
                    ('rf', models['rf']), 
                    ('polsvm', models['polsvm'])],
        voting='hard')
    models['bag'] = BaggingClassifier(
        DecisionTreeClassifier(random_state=r_state), n_estimators=n_est,
        bootstrap=True, random_state=r_state)
    models['adab'] = AdaBoostClassifier(
        DecisionTreeClassifier(random_state=r_state), n_estimators=n_est,
        algorithm="SAMME.R", learning_rate=lr, random_state=r_state)
    models['grab'] = GradientBoostingClassifier(
        random_state=r_state)

    return models

from sklearn.metrics import accuracy_score
import time

def evaluate_model(model, X_train, X_test, y_train, y_test):
    start = time.time()

    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)
    
    elaptime = time.time() - start
    acc = accuracy_score(y_test, y_pred)
    return acc, elaptime

models = get_models()

results, names, times = list(), list(), list()

for name, model in models.items():
    acc, elaptime = evaluate_model(model, X_train, X_test, 
                                   y_train, y_test)
    results.append(acc)
    times.append(elaptime)
    names.append(name)
    print('%s\t %.4f (time: %.3f)' % (name, acc, elaptime))

compare_results=results.copy()
compare_times=times.copy()
compare_names=names.copy()

from sklearn.ensemble import StackingClassifier

def get_stacking(models, nfold=5):
    layer0 = list()  
    layer0.append(('sgd', models['sgd']))    
    layer0.append(('rf', models['rf']))
    layer0.append(('polsvm', models['polsvm']))
    layer0.append(('adab', models['adab']))  
    layer0.append(('grab', models['grab']))
    layer1 = LogisticRegression()
    
    model = StackingClassifier(estimators=layer0,
                              final_estimator=layer1,
                              cv=nfold)
    return model


modelstack = dict()
modelstack['stack'] = get_stacking(models)

results, names, times = list(), list(), list()
for name, model in modelstack.items():
    acc, elaptime = evaluate_model(model, X_train, X_test, 
                                   y_train, y_test)
    results.append(acc)
    times.append(elaptime)
    names.append(name)
    compare_results.append(acc)
    compare_times.append(elaptime)
    compare_names.append(name)
    print('%s\t %.4f (time: %.3f)' % (name, acc, elaptime))


########################
##### YOUR METHOD ######
########################
# MUST: You should capture the below function in the report!
def get_stacking2(models, nfold=5):
    layer0 = list()
    ### append your chosen models as many as you want
    layer0.append(('rf', models['rf']))
    layer0.append(('dt',models['dt']))

   

    ### You can change layer1 if you are interested in though it is not recommended cuz it's hard work
    layer1 = LogisticRegression()
    
    model = StackingClassifier(estimators=layer0,
                              final_estimator=layer1,
                              cv=nfold)
    return model
from xgboost import XGBClassifier
modelstack = dict()
modelstack['KIMCHANHO_stack'] = get_stacking2(models)

your_results, your_names, your_times = list(), list(), list()

for name, model in modelstack.items():
    acc, elaptime = evaluate_model(model, X_train, X_test, 
                                   y_train, y_test)
    your_results.append(acc)
    your_times.append(elaptime)
    your_names.append(name)

print('%s\t %.4f (time: %.3f)' % (str(your_names[0]), float(your_results[0]), float(your_times[0])))

## checking/printing whether yours is better or not

diff = float(your_results[0]) - float(results[0])
dtime = float(times[0]) - float(your_times[0]) 
if diff > 0:
    print("Success:")
    print('%s is better than %s at acc %.4f (saving time: %.3f s)' 
            % (str(your_names[0]),str(names[0]), diff,dtime ))  
else:
    print("Failed")


for i in range(0,len(compare_results)):
    print()
    diff = float(your_results[0]) - float(compare_results[i])
    dtime = float(compare_times[i]) - float(your_times[0]) 
    if diff > 0:
        print("Success:\n")
        print("%s acc: %.4f" %(str(your_names[0]),your_results[0]))
        print("%s acc: %.4f" %(str(compare_names[i]),compare_results[i]))
        print('%s is better than %s at acc %.4f (saving time: %.3f s)' 
            % (str(your_names[0]),str(compare_names[i]), diff,dtime ))
      
    else:
        print("Failed")
# MUST: You should capture the below running result in the report!