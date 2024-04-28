import pandas as pd
import os
from sklearn.metrics import accuracy_score
from pycaret.classification import *
import warnings
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.metrics import confusion_matrix
import seaborn as sns
import numpy as np

warnings.filterwarnings("ignore")


"""
용도: 정상 행동과 낙상 위험 행동 분류 모델 평가

코드실행 결과
./fall_detect_model 폴더에 저장된 모델을 이용하여 정상 행동과 낙상 위험 행동에 대한 분류 진행
결과 값을 csv파일로 저장 
(저장 경로: ./result/)



혼동행렬 이미지 저장(저장 경로: ./result/confusion.png)
"""


def save_confusion_matrix(y_true, y_pred, save_path):
    # 혼동행렬 계산
    cm = confusion_matrix(y_true, y_pred)

    # 혼동행렬 시각화
    fig, ax = plt.subplots()
    sns.heatmap(cm, annot=True, ax=ax, cmap="Blues", fmt="g")

    # 라벨 추가
    ax.set_xlabel("Predicted labels")
    ax.set_ylabel("True labels")
    ax.set_title("Confusion Matrix")
    ax.xaxis.set_ticklabels(["Negative", "Positive"])
    ax.yaxis.set_ticklabels(["Negative", "Positive"])

    print("Complete save confusion_matrix image")
    # 이미지로 저장
    plt.savefig(save_path)

    plt.show()


def fall_detect_predict(csv_file, gt_csvfile, model_path, save_path):
    pred_df = pd.read_csv(csv_file)
    gt_df = pd.read_csv(gt_csvfile)

    final_model = load_model(model_path)
    pred_list = predict_model(final_model, pred_df)["prediction_label"].to_list()
    pred_df["pred"] = pred_list
    gtlist = gt_df["gt"].tolist()

    save_csv_path = os.path.join(save_path, "result.csv")
    pred_df.to_csv(save_csv_path)
    print("Complete save result.csv")

    save_confusion_matrix_path = os.path.join(save_path, "confusion.png")
    save_confusion_matrix(gtlist, pred_list, save_confusion_matrix_path)

    # accuracy score
    accuracy = accuracy_score(gtlist, pred_list, average="macro")
    accuracy *= 100

    print(f"F1 Score : {accuracy:.2f}")


def main():
    csv_file = "./data/csv/train.csv"
    gt_csvfile = "./data/csv/gt.csv"
    model_path = "./fall_detect_model/model.pkl"
    result_path = "./result"
    fall_detect_predict(csv_file, gt_csvfile, model_path, result_path)


if __name__ == "__main__":
    main()
