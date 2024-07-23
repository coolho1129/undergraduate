# Improved Seam Carving for Video Retargeting


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
    

## 3. Preliminaries

Seam : 위에서 아래 방향 또는 좌측에서 우측 방향으로 진행되는 pixel의 monotonic하면서 connected한 path

seam을 삭제하는 경우 : image size가 수평 또는 수직 방향으로 차원이 축소됨.

⇒ 픽셀의 minimum energy path를 잘라낸다.

비디오에서는 각 shot의 입자성 때문에 단순히 seam carving을 적용하는 것은 문제가 생긴다. ( Figure 2 )

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/4ea6ca89-23b1-451f-8338-df05bbe29a77)

그래서 개별적인 frame에 대해서가 아닌 모든 비디오 프레임에 대해 계산해야한다.

- static seam 방식
    
    각각의 이미지를 독립적으로 energy function을 적용한 뒤 최대 energy value를 각 픽셀에 취해서 계산한다.
    

추가적으로, 아래 식을 통해 공간적인 L1 norm을 시공간적인 L1 norm으로 확장할 수 있다. 

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/baad4dc3-ed76-4ac3-ab09-4c0f3c2a8300)



이 때, α는 [0,1] 구간에 존재하며, 실험적으로 0.3이 좋다는 것을 알아냈다.

Figure 3 을 통해 global energy map과 static seam이 비디오의 삭제 작업에 좋다는 것을 알 수 있다. 

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/e46dee21-4bde-4121-a5a2-9c4e47e44ae6)


static method의 장점 : 간단하고 빠르다. 고정된 camera에서 좋은 성능을 가진다.

하지만, 더 복잡한 비디오 장면에서는 적용 X

그래서 video seam을 connected 2D maniford “surface” 로 정의하고 surface의 교차점으로 정의한다. seam은 시간이 지나면서 바뀔 수 있다. (Figure 1)

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/eef0c103-f1a8-49a6-b90b-303bf2bcd865)


2D를 처리할 수 있는 방법이 없기 때문에 (DP 포함) graph cut이라는 또 다른 알고리즘을 사용해야한다.
 


## 4. Seam Carving using Graph Cuts

seam carving operator 

→ miminum cost graph cut problem으로 해결한다. 

** graph edges를 arcs로 칭하겠음. ( image의 edge와 용어 혼동을 피하기 위함)

- grid-like graph
    
    S : source, T : sink
    
    ⇒ 모든 노드는 픽셀을 나타내고 인접한 픽셀끼리 연결되어 있다. 
    
    S/T cut (simply a cut ) C : 두 개의 disjoint한 subset S와 T로 그래프의 노드들을 분할하는 것으로 정의한다.
    
    C 의 cost : 경계에 있는 arcs (p, q)의 cost의 합 
    
    이때, 서로 반대에 있는 arcs는 서로 영향을 미치지 못한다.
    

⇒ 최적의 seam은 cost가 가장 작게 자른다.

과거 DP → graph cut 과정은 이미 진행되었지만, valid seam을 만들어 내지 못한다. 

- valid seam
    1. monotonicity : the seam must include one and only one pixel in
    each row (or column for horizontal seams).
    2. connectivity : the pixels of the seams must be connected.

### 4.1 Graph Cuts for Images

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/babcb147-0521-4337-9c33-00001900da72)


내부 노드 : 네 개의 이웃을 가짐 ( 위, 아래, 왼쪽, 오른쪽 )

arcs의 weight는 각 상응하는 픽셀의 차이로 정의함.

- horizontal

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/3e1feff4-cdc1-4a92-a6f1-46b4d4d8d4b8)


- vertical

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/53c67337-f210-4880-86af-f0a30b07ed05)


**⇒ Figure 4-(a)**

valid seam을 위한 monotonicity 추가 

→ 수평적인 node들에 한해 방향이 다르면 다른 weight를 주어야함.

forward arcs (→) : 기존의 식대로 적용

backward arcs (←) : 무한대의 weight 적용

**⇒ Figure 4-(b)**

graph cut과 기본 DP의 가장 큰 차이점은 connected path에 대한 제약 조건이 없다는 것이다. cut은 여러개의 수직 arcs를 통과하게 되면서 부분적으로 연결된 seam을 만들 수 도 있다. → seam의 공간적, 시간적 연속성을 보존해야한다.

vertical arcs와 horizontal arcs의 가중치를 결합하여 우리는 기본 DP 알고리즘을 사용하여 만들 수 있는 graph와 동등한 형태를 만들 수 있다. 

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/106667ac-83ae-425d-a10d-468da2b727cd)


**⇒ Figure 4-(c)**

** Figure 4-(d)는 Section 5 에서 소개한 new forward energy 를 사용한 모습이다.


### 4.2 Graph Cuts for Video

source node, sink node를 모두 왼쪽과 오른쪽 columns(vertical이니까)과 연결 할 것이다. 

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/b08b567a-0cda-4d9e-980c-bc2964c523a5)


Figure 5 처럼 모든 graph cut을 이용하여 분할하면 3D 영역 안쪽에 maniford가 정의된다. 이 cut은 시간에 대해 monotonic하다. 또한, space와 time에 대해 globally하게 optimal 하다.

graph cut algorithm : 다항시간 소요 (linear running time)

계산 시간은 nodes time의 수에 의존하기 때문에, arcs의 수가 많으면 화소의 수가 2배가 됨 ⇒ 실현 불가능함. (높은 해상도의 이미지 등에서 이미 한계가 발견됨)

> Coarsening (대략적으로 그래프 샘플링하여 간소화)→ Refinement (그래프 정밀 조정) 의 과정으로 graph cut 진행



## 5. Forward Energy

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/c5d4eeda-e7d3-47b1-bba1-a18c387df82e)


이때까지는 energy의 ‘삭제’ 만 고려하였고 그 결과가 Figure 6 번에 나타나고 있다. seam이 삭제 되면서 에너지는 삭제되는 것 처럼 보이지만, 추가적으로 서로 이웃하지 않은 arcs들이 이웃하게 되면서 에너지가 삽입이 된다. 

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/469d1122-2815-4978-8986-6d1ff2f793d3)


위 식을 통해 삽입된 에너지의 양을 알 수 있으며, Figure-6(b)의 그래프에 따르면 Et의 변화량은 실제로 증가하고 있다. 

이 관찰에 따라 우리는 optimal seam을 고르는 새로운 기준을 제안했다.,

새로운 기준은 결과 이미지를  ‘forward’하는 것 처럼 보인다.

**⇒ 우리는 image에 적은 양의 energy를 삽입하는 seam을 찾을 것이다.** 

( 기존에는 energy를 적게 삭제하는 방향 (=backward) 의 seam을 찾았음 )

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/cc290784-f503-45df-b572-c12042e35022)


connected seam의 삭제 이후 삭제된 곳을 지역적으로 살펴보면 3가지 상황이 일어날 수 있다. (Figure 7)

pixel-edges : 삭제로 인해 새로 만들어진 edge?

### 5.1 Forward Energy in Dynamic Programming

가능한 케이스(Figure 7)의 cost를 아래와 같이 정의할 수 있다. 

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/f8b1b444-e670-47eb-8871-1264832f15fc)


우리는 위 세 cost를 새로운 DP 계산식을 이용하여 정의하였다. 

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/852c5a53-9f7f-4952-baf8-2e3ea307212f)


P(i, j)는 부가적인 픽셀 기반 에너지 측정이다. 

### 5.2 Forward Energy in Graph Cut

graph cut으로 forward enery를 정의하기 위해서는 세가지 가능한 seam 상황에 대한 cost를 정의한 arc weight로 graph를 만들어야한다.

Figure 4(d) 가 이 연산을 적용하였다. 

 
![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/945e39db-34cc-419e-b58f-9b45809b3839)


new horizontal pixel-edge p_i, j-1 p_i, j+1 이 정의되었다. (p_i,j가 삭제되었기 때문) 

추가적으로, Left가 삭제되는지 Right가 삭제되는지의 차이를 

Left and Right neighbors

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/d1074c03-9c88-4b0c-8aac-b27f2084c9d3)


로 정의하겠다.

1) monotonicity → p_i, j+1 과 p_i, j 를 infinite weight arc로 연결한다. (backward)

2) connectivity → diagonal backward 추가

3) new vertical pixel-edges에 의해 삽입된 에너지 설명 (Figure 7(b))

- Figure7(b) : no new vertical edges : no energy inserted
- Figure7(a) : upward vertical arcs
- Figure7(c) : downward vertical arcs

upward

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/e4b80f54-9afa-4329-9c30-44c40e6bb73d)


downward ( -LU 표현 방식을 통해 시작점과 끝점의 반대를 의미함)

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/1da3535d-8fe8-4d6e-a0c9-2d2060955d9a)


weight - LU

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/a06b702a-2fec-4d69-8999-ec399f9ada04)




Figure 10, 13 : 향상된 forward energy가 사용된 graph cut 방식을 이용한 결과물

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/cd461a3a-4920-43ae-a481-0ba3089b415c)


![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/9e325c23-eb6a-4414-80d3-183443e832cb)


비디오에서는 seam direction에 의존하여 3D video cube를 잘랐다.  X x T를 하는 방식과 동일하게 X x Y 에서 진행하였고, temporal pixel-edges를 만들었다. 

⇒ 잘 작동되었다.

## 6. Results

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/8d86d821-019a-435a-9f29-d0749fadd3f1)

![image](https://github.com/coolho1129/Metaverse-Background-Research/assets/87495422/3270f5ee-62dd-4547-a6e8-ba0f9836420f)

