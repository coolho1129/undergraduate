# Drop the GAN: In Defense of Patches Nearest Neighbors as Single Image Generative Models

## 논문 원문
[GPNN.pdf](https://github.com/coolho1129/Metaverse-Background-Research/files/12799375/GPNN.pdf)

## 요약

목적 : PNN 기반 GAN -> GPNN
새로운 GAN과 유사한 생성 기능 + 가장 가까운 이웃 패치 기반 방법(PNN) ⇒ 두 개의 장점을 모두 얻음.
GPNN은 단 몇초 안에, 최적화하고 학습할 필요없이 하나의 통합된 framework로 새로운 생성과제를 수행. 

***GAN과 유사한 새로운 생성 기능***
GPNN은 SinGAN의 multi-scale architecture과 매우 비슷한 architecture를 가짐. 
각 scale은 source xn과 유사한 patch distribution을 사용하여 다양한 output yn을 생성하는 단일 image generator G(PNN)로 구성됨. 

***PNN consists of 6 main algorithmic steps***
1. Extract patches
2. Compute distances
3. Compute normalized scroes
4. Find NNs
5. Replace by NNs
6. Combine patches

## 상세분석

## Abstract

기존의 문제점 : input과 생성된 output 사이의 패치 유사성이 최대가 되도록하는 최적화 과정을 기반으로 둠. 싱글 이미지 GAN은 오랜 훈련 시간을 요구한다. 그리고 인공적인 느낌이 나고 모드 붕괴등의 최적화 문제가 생긴다. 

제안 기법 : 논문에서는 어떠한 훈련없이 몇초안에 통합된 framework를 제안한다. patch 기반의 최적화가 필요없는 framework를 사용. 추측을 시작으로 가장 가까운 이웃 패치 검색을 통해 세부 사항을 더욱 세분화한다. 

image editing, reshuffling, retargeting, structural analogies, image collage, conditional inpainting등의 넓은 범위의 응용도 보여준다. 

결론/결과 : 논문의 방법이 빠를뿐만 아니라 놀라운 결과를 보여준다.(덜 인공적, 더욱 현실적인 구조)

## 1. Introduction
**Single-image generative model** : 비지도 학습이고 하나의 이미지의 패치 분포를 캡쳐하여 이미지 합성과 조작을 수행. 클래식한 방법은 input image와 생성된 output image 사이의 작은 patch의 유사성을 최적화하는 것에 기반한다. (image completion, texture synthesis, image summarization/retargeting, collages, image reshuffling,등). 

visual coherence : output image에 input image의 패치들을 포함. 

visual completeness : input은 output의 패치들이 포함되어야 한다. 

⇒ output에 어떠한 새로운 인공물이 추가되어서도 안되고 중요한 정보를 잃어서도 안된다. 

**Deep Single-Image Generative model** : 심층 내부 학습의 자연스러운 확장. 다양한 생성 결과를 보여줌. fully convolutional을 통해 하나의 input image의 패치 분포를 학습하고 같은 패치 분포의 새로운 이미지를 생성. SinGAN, InGAN등이 포함. 

### However,

세가지 문제점 존재 

- 각각의 tassk에 대한 오랜 학습 시간을 요구
- 모델 붕괴와 같은 최적화 문제 발생
- 클래식 패치 기반 방법보다 더 떨어지는 시각 화질을 생성.

**논문에서는 다시 패치에서 가장 가까운 이웃을 고려하는 것을 제안.**

**새로운 GAN과 유사한 생성 기능 + 가장 가까운 이웃 패치 기반 방법 ⇒ 두 개의 장점을 모두 얻음**.

single-image GAN method는 noise → image를 생성하는 unconditional 방법에 비롯함.  언급된 단점은 주로 GAN 기반 모듈에서 비롯됨. 

따라서 논문은 “drop the GAN”을 제안하고, 이 모듈을 간단한 Patch Nearest-Neighbor(PNN) 모듈로 교체.(unconditional 특성은 유지) 

⇒ **Generative Patch Nearest-Neighbor(GPNN)** 

GPNN 결과 : noise input에서 다양하고 매우 높은 퀄리티와 single-image GAN보다 빠른 이미지 생성을 도출. 

GPNN은 단 몇초 안에, 최적화하고 학습할 필요없이 하나의 통합된 framework로 새로운 생성과제를 수행. 

single-image GAN과 달리, 매우 빠르고 우수한 시각적 결과 생성

classical patch-based method와 달리, GAN의 비결정적인 특성과 거대하고 다양한 output, 그리고 새로운 생성 과제와 가능성을 따름. 

- non-deterministic
    
    : 동일한 입력이 주어지더라도 매번 다른 방법으로 다른 결과를 도출함. (결정론적과 반대)
    

GPNN의 응용

1. 다양한 이미지 생성, image editing & reshuffling, image retargeting, structural analogies, image collages
2. 새롭게 도입된 과제인 “conditional inpainting”

## 2. Method

GPNN의 구조가 노이즈를 주입한 input으로 multi-sclae 구조를 사용한다는 점에서 SinGAN과 비슷, 그러나 각 scale마다 non-parametric인 PNN을 사용. 각 scale 마다 source image에서 비슷한 patch 분포로 새로운 이미지를 생성. 
![Untitled](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/7beb5ab2-4f07-4289-b5ce-471ee020493a)


### 2.1 Multi-scale Architecture

image의 각 scale에서 다른 정보가 포착된다는 것은 이전부터 인식되어 왔다. 

GPNN의 대략적인 구조 설명

x : source image, 피라미드{x0, … , xN}로 생성. xn은  x를 r^n 만큼 다운스케일한 것.(논문에서는 r=4/3)  

모든 scale에서 p x p의 똑같은 패치 사이즈를 사용. 

피라미드 N의 깊이는 p가 이미지 높이의 대략 절반정도가 되도록 선택됨. 

**새로운 이미지 yn은 초기 추측인 ~yn+1에 따라 해당 스케일 xn에서 소스 이미지의 실제 패치를 사용하여 PNN 생성 모듈에 의해 생성됩니다.**

PNN은 각 sclae에서 output image와 source image의 내부 확률의 유사성을 강화. 

coarset level에서, 초기 추측은 노이즈를 주입한 source image이다. 

![초기추측](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/40cc7375-3bfb-45dd-8000-891d10abf8cf)

coarset scale은 이미지에서 객체의 배열을 정의한다.

해당 규모로 노이즈를 주입하면 가장 가까운 이웃이 거의 무작위로 검색되므로(패치의 평균은 예상대로 동일하게 유지됨) 전역 배열에 다양성이 유도되지만 PNN은 일관된 출력을 유지합니다.

다른 노이즈 map Zn의 사용은 다양한 이미지 생성을 위한 기본이고, 초기 추측에서 다른 선택은 다양한 추가적인 어플리케이션을 위한 기반이다. 

finer scale에서, 초기 추측은 coarser level의 업스케일된 output이다. 

![업스케일](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/a10348c3-a2fc-47c3-870a-41856a02673a)


각 scale의 output은 더 거친 scale의 output을 개선한 것이다. 따라서 최종 output y=y0는 모든 스케일에서 x의 내부 확률을 공유한다.

### 2.2 Patch Nearest-Neighbors Generation Module

PNN의 목표 : 초기 추측 이미지 ~y(n+1)과 source image xn을 기반으로 새로운 이미지 yn을 생성하여 구조가 ~y(n+1)와 비슷하고 내부 통계는 xn과 매치되게 하는 것. 

이를 위해 PNN은 초기 추측 ~y(n+1)의 패치를 소스 이미지 xn의 이미지로 교체

GPNN은 고전적인 패치 기반 방식과의 2개의 주된 차이를 소개 

1. Query-Key-Value patch search strategy : 생성된 output의 시각적 퀄리티 향상
2. 새로운 normalized patch-similarity measure : 최적화 없는 방법에서 시각적인 완성을 확실히 함. 

고전 patch-based method는 Query-Reference scheme 사용. 

→ **query는 초기 추측(~y(n+1))이고 reference(~x(n+1))는 source image**이다. 각 query patch는 reference patch로 교체된다. 이것은 output과 source의 내부 통계 사이의 유사성을 높인다. 

그러나 이러한 scheme는 query와 reference patch 사이 상당한 분포 변화가 있으면 실패한다.

예를 들어 query patch가 흐리면 reference patch도 흐리게 매치됨. 

***Query-Key-Value patch search strategy*** 

이러한 문제를 극복하기 위해 PNN은 Query-Key-Value scheme를 사용. 

PNN에서는 lookup patch와 replacement patch가 다르다. 

~y(n+1)의 각 query patch Qi에서, 우리는 reference image ~x(n+1)의 upscaled 버전에서 Qi와 가장 가까운 key patch Kj를 찾는다.

그리고, 찾은 Kj를 상응하는 각 scale, xn에서의 source image에서 value patch Vj와 교체한다.

blurry query patch는 blurry key patch와 비교되지만 sharp(블러처리가 아) value patch로 교체됨.

***새로운 normalized patch-similarity measure***

가장 가까운 이웃을 찾는데 사용되는 지표 

input에서의 시각적 data가 생성된 output에서 잃어버리지 않았는지 확인하는데 필수적임. 

완전성은 픽셀에 대한 반복적인 최적화 과정을 통해 강화된다. 

PNN은 일반적인 L2 메트릭을 대체하는 normalized patch similarity score(정규화된 패치 유사성 점수)를 사용하여 완전성을 강화한다. 

유사성 점수는 patch-nearest-neighbor을 찾는데 유용하고 query에서 잘 표현되지 않은 주요 patch를 선호하여 실제로 최적화 없는 방식으로 시각적 완성도를 장려합니다.

PNN consists of 6 main algorithmic steps

---

![pnn](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/b9e505ea-0e78-415c-8eb1-154f6de86b0f)


1. **Extract patches** :
    
![pnn moudle](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/2b969455-6b9d-419e-b673-2f3248d0d2f2)

    
PNN은 sharp source image xn과 추기 추측 ~y(n+1)(이전 scale에서 생성된 output의 upscaled version이라서 블러로 됨)을 받음. 

초기 추측으로부터 patch는 query patches로 추출된다. 

blurry query patch의 가장 가까운 이웃은 더 거친 source image, ~x(n+1)를 upscaling되어 얻어진 유사한 blurry image(Key)에서 검색된다. 여기서의 유사한 blurry image가 key patch pool이다. 

상응하는 sharp patches는 sharp source image xn에서 추출되고, 이것을 value patches pool(V)라고 한다. 

key와 value는 대응을 유지하기 위해 같은 방법으로 정렬된다.(같은 위치의 patch들은 둘의 pool에서 같은 index를 가짐)

 patch가 겹치므로 동일한 픽셀이 여러 patch에 나타날 수 있습니다.

1. **Compute Distances** :

각 query patch Qi와 각 key patch Kj 사이의 MSE 거리를 계산하고, distances matrix D(i,j)에 저장한다.

Di;j 컴퓨팅의 병렬 특성을 활용하고 속도를 위해 GPU에서 실행합니다.

2. **Compute Normalized Scores** : 

시각적 완전성을 위해, PNN은 query에서 누락된 key patch를 favor하는 유사성 스코어를 사용. 

이것은 output에서 선택되고 나타나게 하는 찬스를 증가시켜서 완전성을 향상시킨다. 

score는 key 당 factor의 거리를 정규화한다.

![정규화식](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/45317563-a77b-41b3-94a3-8cc7db482e5b)

key patch Kj가 query에서 누락되었을 때, normalization term은 커지고 score는 매우 작아진다. 다시 말해, key patch가 query에서 나타났을 때, 정규화 인자는 알파에 가까워진다. 

매개변수 알파는 완전성 정도를 제어하는 손잡이로 사용된다. 

여기서 알파가 작은 것은 완전성을 장려하며 알파 >> 1은 본질적으로 MSE를 사용하는 것과 동일합니다.

3. **Find NNs** :

각 query patch Qi에서 그것과 가장 가까운 key patch의 index를 찾음. 

![find_nn](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/1769e669-2dec-4686-a593-992f83ec07f4)

4. **Replace by NNs** : 

각 query patch Qi를 가장 가까운 이웃의 value와 교체함. output은 Oi로 표현

5. **Combine Patches** :

겹치는 패치가 이미지로 결합된다. 여러 개의 겹치는 패치에 나타나는 픽셀은 가우스 가중 평균을 사용하여 집계된다. 

매우 다른 겹치는 patch를 결합하는 것은 일관적이지 않고 인공적인 결과를 야기한다.

이를 완화하기 위해 PNN은 각 scale에서 T time을 적용한다.

첫 번째 반복에서, 초기 추측은 위에서 설명한 것과 같다. 추가 반복에서는 이전 출력(업스케일링 없음)이 초기 추측으로 사용된다.

## 3. Results & Evaluation

SinGAN과 GPNN의 성능 비교 -random image generation의 주요 application

시각적 품질과 사실성에서 실질적인 우위를 보여준다.

**Data** : 첫번째로 SinGAN에서 사용된 50개의 image를 사용하고, 두번째는 Single Image Generation Dataset을 사용한다.(single image generation task의 다른 중요한 측면을 평가하기 위한 16개의 image set)  

**Visual results** : visual quality, realistic structure, diversity 세 개의 GPNN 특성에서 다양한 이미지 생성 결과를 보여줌. 

visual quality - 결과는 어떠한 인공물도 없이 선명해 보인다.

realistic structure - 생성된 이미지는 진짜 같아 보이고 구조도 의미 있어 보인다.

diversity - GPNN은 높은 결과의 다양성을 생성한다. 

![diverse](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/246b0efd-3bb6-4b2f-a008-9db8e2916e7c)

![singan비교](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/a7d8fec7-a296-401f-9ad5-e3ac178e5bef)

GPNN에 의해 성성된 이미지는 매우 현실적으로 보이는 반면, SinGAN은 종종 인공물이 보이고 구조가 의미있어보이지 않는다.

![table](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/83eb8837-bdff-4390-90ce-f9d37727f686)

**Quantitative evaluation** : GPNN과 SinGAN 사이에 양적 비교를 보여준다. 

SIFID 측정값 - 소스와 생성된 image patch 분포 사이의 거리를 측정

NIQE - 참조 없는 품질 평가를 위해 사용

GPNN이 SIFID, NIQE 에서 모두 SinGAN보다 우위에 있음.

**Qualitative Evaluation - Extensive User-Study** : 

결과적으로 GPNN 점수는 모든 setup에서 SinGAN보다 높은 결과를 보여준다.

GPNN은 50프로에 매우 가까운 결과를 도출한다. 

unlimited time을 가진 관찰자가 실제 이미지와 GPNN 생성 이미지를 거의 구별할 수 없다는 사실은 생성된 결과의 높은 현실성을 의미. 

## 4. Additional Applications

하나의 framswork로 다양한 응용에 적용할 수 있다. 

GPNN에서 피라미드 깊이 N, 거친 레벨에서 초기 추측 ~y(N+1), 등 몇개의 기본 파라미터만 수정하여 응용을 얻을 수 있다. 

### Retargeting

goal : source image에서 패치 분포를 유지하면서 target size로 resize하는 것

input image를 target size로 resize 시작하고 r^N만큼 다운스케일하고, 이를 초기 추측에 넣음. 

피라미드 깊이 N을 패치 크기 p의 x4가 되도록 설정, 하이퍼파라미터 알파는 작은 값으로 세팅하여 완전성을 높임.   

![retargeting](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/240dee15-9979-4cfb-98f8-c627b154fa54)

### Image-to-image and Structural Analogies

style-transfer, domain-transfer, structural-analogies. 

input image A,B가 있으면 A의 객체와 B의 배경을 합침. 

GPNN에서 source image x는 input image A의 패치 분포, 추기 추측 ~y(N+1)은 다운스케일된 정렬된 input image B.

객체 size에 따라 피라미드 깊이 N이 변화함. 하이퍼 파라미터를 작게 설정. 

![structureal](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/cd0e1aae-9647-4a70-b620-1bb01f5a57c3)

### Conditional Inpainting

GPNN에서 초기 추측 ~y(N+1)은 source image x의 다운스케일한 버전. 피라미드 깊이 N은 다운스케일된 image의 occluded part의 pxp 사이즈에서 설정됨. 

### Image Collage

![collage](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/2bc25fbf-b9b1-4423-9716-ec0424752b35)

### Image Editing


## 5. GANs vs. Patch Nearest-Neighbors: Pros & Cons

먼저 simple classical patch-based methods(GPNN을 통해 예시)의 놀라운 고유 이점의 원인을 분석. 

그럼에도 불구하고 single-image GAN에는 simple patch nearest-neighbor methods로는 실현할 수 없는 몇 가지 중요한 기능이 있음. 항상 "GAN 삭제"를 원하지 않을 수도 있음

이러한 classical patch-based methods(GPNN 포함)의 고유한 한계도 논의됨.

### Advantages

single-image GAN은 단일 이미지의  patch-distribution을 암시적으로 학습하는 반면, classical patch-based approach는 전체 patch-distribution(이미지 자체)를 명시적으로 유지하고 가장 가까운 이웃 패치 검색을 통해 직접 액세스합니다.

1. Visual Quality : patch nearest-neighbor search을 통해 생성된 output image는 input image에서 직접 가져온 원본 image patch로 구성된다. 반대로, GAN의 output은 최적화 과정을 통해 합성된다. 따라서 GPNN은 GAN보다 original input patch에 더 충실한 patch를 가진 image를 생성한다. 이렇게 하면 원하지 않는 시각적 artifact가 적어 더 선명한 출력이 생성됨.
2. Runtime : patch-based method의 runtime은 GAN과 비교해서 hour에서 second로 줄어든다. 더욱이 nearest-neighbor search는 다른 image patch들과 독립적이고 병렬로 수행될 수 있다. GPU computing 사용
3. Visual Completeness : GAN은 높은 가능성의 patch를 생성하면서 학습되는 반면 어떠한 메커니즘도 완전성을 가화하지 못한다. 완전성의 부족은 모드 붕괴로 겪는 GAN의 자연스러운 경향에 의해 더욱 심화됨.  대조적으로, classical patch-based method는 예를 들어 input image와 output image 간의 bidirectional(양방향) patch similarity을 최적화하거나, GPNN의 패치별 정규화 점수를 사용하여 최적화 없는 방식으로 완전성을 명시적으로 적용할 수 있습니다. 
4. Visual Coherence (realistic image structures) : 
5. Controlling diversity vs global structure : 

### Limitations

1. Generalization : patch-based method는 개별의 patch 분포를 사용하는 반면, GAN은 continuous 분포를 학습한다. 따라서 GAN은 학습된 분포로부터 높은 가능성의 새로운 patch를 생성한다. 이 능력이 patch-based method에서는 결핍된다. 
2. Continuous output generation : 잠재 input에서의 작은 변화는 생성된 output에서의 작은 차이를 만든다. 이것은 latent space interpolation(보간법, 채워넣음)와 다른 부드러운 조작을 가능하게 한다.
반면에 nearest neighbor search는 본질적으로 이산적임.
classical patch-based method에서 continuous (interpolation이나 animation)을 막음.
3. Mapping to patches vs Mapping to pixels : classical nearest-neighbor method에서는 nearest neighbor search는 추출한 patch의 질을 최대화하지만, 최종 output pixel의 질은 그렇지 않다. output image의 형식은  겹치는 patch의 경험적 평균화가 포함된다. 이것은 patch-based method에서 지역적인 블러를 생성한다.
GAN 분별망은 또한 그들의 반복적인 영역의 사이즈에서 output patch를 판단한다. 그러나 생성망은 pixel-based 그레디언트를 받아들이기 때문에 각 output pixel에서 직접적으로 최적화할 수 있다.

## Are GANs “Fancy Nearest Neighbors Extractors"?

GAN도 잘 생성하지만 블러나 인공물이 추가된 output이 나온다. 그에 비해 GPNN은 자연스러운 결과를 도출해낸다. 하지만 이것이 제한된 능력이다.
