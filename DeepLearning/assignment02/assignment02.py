from ultralytics import YOLO
from os import makedirs
import cv2


def detection(img_path, save_path):
    model = YOLO("yolov8n.pt")
    img_name = img_path.split("/")[-1]
    results = model(img_path)

    makedirs(output_path, exist_ok=True)

    for result in results:

        img = result.orig_img

        for box in result.boxes:
            x1, y1, x2, y2 = map(int, box.xyxy[0])
            confidence = box.conf[0]
            label = box.cls[0]

            # 경계 상자 그리기 (두께 3, 색상 빨간색으로 변경)
            cv2.rectangle(img, (x1, y1), (x2, y2), (0, 0, 255), 3)

            # 텍스트 그리기 (폰트 크기 1, 두께 2)
            text = f"{model.names[int(label)]}: {confidence:.2f}"
            cv2.putText(
                img,
                text,
                (x1, y1 - 10),
                cv2.FONT_HERSHEY_SIMPLEX,
                1,
                (0, 0, 255),
                2,
                cv2.LINE_AA,
            )
            save_path = f"{output_path}/result_{img_name}"
            cv2.imwrite(save_path, img)


output_path = "./output/"
oriimg_path = "./coolho.jpg"
watermarked_LU_path = "./watermarked_LU.jpg"
watermarked_person_path = "./watermarked_person_300_800.jpg"
detection(oriimg_path, output_path)
detection(watermarked_LU_path, output_path)
detection(watermarked_person_path, output_path)
