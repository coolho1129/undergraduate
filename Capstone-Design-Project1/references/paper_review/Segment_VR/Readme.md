# Object-Ratio-Preserving Video Retargeting Framework based on Segmentation and Inpainting

## 논문 원문

[[Retargeting] Segment_VR(WACVw2023).pdf](https://prod-files-secure.s3.us-west-2.amazonaws.com/374945cc-2ff3-4ca9-aede-e1d0b18cc5aa/24ed039f-03c4-495c-bc49-ee1adc24d5ff/Retargeting_Segment_VR(WACVw2023).pdf)

## 소스 코드

[GitHub - jinjungyu/ORPVR: Video Retargeting Using Instance Segmentation and Video Inpainting](https://github.com/jinjungyu/ORPVR)

## 요약

목적 : video retargeting

이미지 처리 과정 : segmentation → inpainting → resizing → relocating

1. segmentation
    
    각각의 frame 마다 사람(차지 면적이 1% 보다 큰 경우만)을 segment 진행함. 
    
    segment 한 결과를 binary masked 하고 이를 나중에 inpainting에 사용함. 
    
    segment 가 되지 않은 픽셀을 줄이기 위해 여백을 둠.   
    
2. inpainting
    
    비디오 중심 생성 모델과 이미지 중심 생성 모델이 있었는데 이미지 생성 모델은 전 프레임의 정보를 사용하지 않아서 어려움이 있었다. 
    
3. resizing 
    
    해상도에 맞게 크기를 조정하였다. 
    
4. relocating
    
![segvr1](https://github.com/coolho1129/Metaverse-Background-Research/assets/105068708/a772442d-026b-4852-9c09-116289d8f6d8)

    위 알고리즘에 따라 offset을 결정하였다. 
    

한계 :  relocating 과정이 일어나기 때문에 모든 객체를 정확히 탐지하지 않으면 문제가 발생함.

가장자리에 object가 위치할 때  object의 전체part가 없으므로 relocating이 잘 되지 않음.

(이미 객체 정보가 손실되었기 때문)  

## 상세 분석

### Abstract

최근 비디오 플랫폼의 발전 → 과거 영상도 쉽게 접근 가능

⇒ 현재의 기기들과 과거 영상의 비율이 맞지 않는 문제가 발생

현재 사용되고 있는 해결 방안 : 영상의 수평확장 또는 검은 박스 생성

‘retargeting’을 이용하여 예전 영상을 더 넓은 비율의 영상으로 바꾸자.

### introduction

비디오 플랫폼의 발전으로 과거 영상도 쉽게 접근 가능하지만, 영상과 화면의 비율이 다른 문제 발생

⇒ super-resolution 기술로만 다루기에는 무리가 있음. (너비와 높이를 둘다 예측하는 기술로 한쪽 방향으로만 늘리고자하는 우리의 목표와는 상충됨)

선대연구 

- seam carving algorithm
    
    ⇒ large object나 complex image에는 적용이 어려운 한계점 존재
    

딥 러닝의 발전으로 image retargeting task과 관련된 좋은 성능을 가진 모델들이 있음. 

**우리는 딥러닝을 이용한 instance segmentation & inpainting 방식으로 retargeting을 진행하겠다.** 

### Proposed Framework
![segvr2](https://github.com/coolho1129/Metaverse-Background-Research/assets/105068708/f3fbd208-e50f-49fd-a2c8-51e5989b4b51)


### Segmentation

- model : ‘Masked-attention mask transformer for universal image segmentation’ 논문의 참고
- 사람을 중심으로 segmentation을 진행한다.
    
    ( 전체 면적의 1% 이상의 사람만 추출 대상에 해당한다. )
    
- 사람이 물건(기타, 가방 등)을 들고 있는 경우 함께 추출해야하기에 이를 subclass에 추가해둔다.
- segmentation을 진행할 때 약간의 여백을 둘 것이다.

### Inpainting

- model : Towards an end-to-end framework for flow-guided video inpainting
- input : video frame, binary masked frame(segmentation 과정에서 생성됨)
- video inpainting 모델과 image inpainting 모델이 있다.
    
    ⇒ 비디오 모델은 spatio-temporal 정보를 가지고 있어 이미지 모델보다 성능이 좋다.
    

### Resizing and Relocating

- object-removed background image는 16:9로 설정한다.
- relocating은 offset의 위치를 정해야한다. 아래 알고리즘에 따라 작동한다.

![segvr3](https://github.com/coolho1129/Metaverse-Background-Research/assets/105068708/a68cf01d-7179-4a34-b212-15686152f397)

### Result
![segvr4](https://github.com/coolho1129/Metaverse-Background-Research/assets/105068708/20dff6ca-8038-41d2-8f47-78e605316674)

### Ablation study

1. segmentation performance
    
    intersection over union으로 객체를 탐지함.
    
    DAVIS dataset 사용하여 성능 평가함. 
    ![segvr5](https://github.com/coolho1129/Metaverse-Background-Research/assets/105068708/e6f0146e-54c6-4c64-8db4-49cae4b5c0b9)

  
    더 정확도를 높이기 위해 여백을 두고 segmentation을 진행함. 
    
2. inpainting method
    - AOT-GAN : 이미지 처리에는 좋았으나 비디오 처리에서는 별로였다.
    - DFCNET : 시공간 자료를 사용하지 않아서 이상해짐.
    - **E^2FGVI** : 가장 자연스러운 결과를 도출함.
    ![segvr6](https://github.com/coolho1129/Metaverse-Background-Research/assets/105068708/5a9cd65a-3c21-4b0a-abc6-c2b72fb27828)

 
    
3. Optimal Relocation Method
    - Original Coordinates : 같은 프레임에 붙여넣는것 → 오른쪽 edge가 부자연스러움
    - offset coordinates : 늘어난 width 만큼 더해서 위치하는 것 → 왼쪽 edge 가 부자연스러움
    - **dynamic coordinates** : object 의 위치에 따라 다르게 적용하는 방식 ( 위 알고리즘 참고 ) → 자연스러움
    
![segvr7](https://github.com/coolho1129/Metaverse-Background-Research/assets/105068708/060c4a27-5f87-4ba7-bbae-9e880eae2055)


### Discussion & Conclusion

한계점 : 물체가 frame의 edge에서 움직일 때 정확하게 relocating 하지 못한다.
