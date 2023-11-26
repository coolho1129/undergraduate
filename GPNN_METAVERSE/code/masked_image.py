import cv2
import os
import numpy as np
IN_PATH='beforemasked'
OUT_PATH='ourData'

first_dir=os.listdir(IN_PATH)

for fd in first_dir:
    os.mkdir(os.path.join(OUT_PATH, fd))  ##fd=cyberpunk, group, street 등등 
    second_dir_path=os.path.join(IN_PATH,fd)
    second_dir=os.listdir(second_dir_path)
    for sd in second_dir: 
        if(sd=='image'):
            image_path=os.path.join(second_dir_path, sd) #sd=image 또는 mask 
            image_list=os.listdir(image_path)
        elif(sd=='mask'):
            os.mkdir(os.path.join(OUT_PATH,fd,sd))
            mask_path=os.path.join(second_dir_path, sd)
            mask_list=os.listdir(mask_path)
    
    os.mkdir(os.path.join(OUT_PATH,fd,'masked_image'))
    # 이미지와 마스크 로드
    for i in (0,len(image_list)-1):
        print(i)
        if image_list[i]==mask_list[i]: 
            print('a')
            image=cv2.imread(os.path.join(image_path,image_list[i]))
            mask=cv2.imread(os.path.join(mask_path, mask_list[i]),0) # 흑백 마스크로 로드

            # 마스크된 부분을 제외한 이미지 생성
            masked_image = cv2.bitwise_and(image, image, mask=cv2.bitwise_not(mask))
            cv2.imwrite(os.path.join(OUT_PATH,fd,'mask', image_list[i]), mask)
            cv2.imwrite(os.path.join(OUT_PATH,fd,'masked_image', image_list[i]), masked_image)

