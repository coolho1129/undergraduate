# Improved Seam Carving for Video Retargeting

아직 review를 덜마친 상태이며, 추후 review가 완료되면 최종 자료가 업데이트 될 예정임**

## 논문 원문

## Abstract

improved seam carving을 이용하여 video retargeting을 진행하였다. 

- 2D image → 1D seams ⇒ Dynamic Programming
- 3D volumes ( like video ) → 2D seams ⇒ Graph Cuts

Graph Cuts을 적용할 때 Valid Seam ( =monotonic && connected ) 을 만들어 내는 것이 중요하다. 

기존 seam carving은 energy를 최소한으로 덜 삭제하는 것이 목표였지만, 이제부터는 time을 고려해서 seam을 제거할 것이다. 그리고 이 향상된 기준에 graph cut을 어떻게 적용할 것인지에 대해 보여줄 것이다. 

## 1. Introduction

Seam carving : effective technique for content aware image retargeting.

<br>

**기존 seam carving의 한계점 -1**
  
  frame을 독립적으로 보고 resize하는 temporal coherency가 부족함.
  
  ⇒ space-time volume을 관통하는 2D connected manifold 를 만들 것이다. 이 과정은 DP가 적용되지 못하기에 graph cuts을 이용할 것이다. 
  
  하지만, 간단한 graph cut은 valid seam을 만들어내지 못한다. 
  
  seam의 조건 : monotonic, connected 
  
  그래서 valid 한 seam을 graph cut 방식에 대한 이야기를 할 것이다. 

<br>

**기존 seam carving의 한계점 -2**

  seam carving은 두 가지 상황이 발생할 수 있다. 
  
  1. spatial artifacts 의 확대
  2. temporal한 것이 확대됨.
  
  ⇒ 사람의 시각은 움직임에 더 민감하기 때문에, 후자(2번)의 경우 이상하게 보여질 수 있음. 
  
  이를 막기 위해 novel seam carving에 대한 기준을 세움
  
  ⇒ 삽입되는 에너지 뿐만 아니라 삭제되는 에너지까지 고려한다. 

V**ideo resizing의 어려움**

  1. 차원적인 어려움
      
      기존 Dynamic Programming을 3D video cube에 확장시키지 못한다. 
      
  2. 데이터 용량
      
      비디오는 frame의 시퀀스로 이루어져 있어서 데이터 양이 많다. 
    

## 2. Background

## 3. Preliminaries

Seam : 위에서 아래 방향 또는 좌측에서 우측 방향으로 진행되는 pixel의 monotonic하면서 connected한 path

 


## 4. Seam Carving using Graph Cuts

### 4.1 Graph Cuts for Images


### 4.2 Graph Cuts for Video


## 5. Forward Energy

### 5.1 Forward Energy in Dynamic Programming

### 5.2 Forward Energy in Graph Cut

## 6. Results

## 7. Limitations

## 8. Conclusions and Future Work
