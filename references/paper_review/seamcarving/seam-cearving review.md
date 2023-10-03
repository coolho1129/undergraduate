# Seam Carving for Content-Aware Image Resizing

## Abstract

효과적인 image resizing을 위해서는 geometric constraints뿐만 아니라 이미지 내용도 고려해야 한다.
→ 콘텐츠를 인식하면서 image reisizing하는 seam carving을 제안

*seam: a connected path of low energy pixels in an image

Seam carving 기술은 이미지 사이즈를 확대,축소할 수 있게 해 준다. 또한 content enhancement와 객체 제거를 하는 데 사용될 수 있다.

***keywords***: Image resizing, Image retargeting, Image seams,Content-aware image manipulation, Display devices

# 1. Introduction

현재까지 이미지는 디지털 미디어의 핵심 요소 중 하나이지만 일반적으로 크기가 고정되어 있고 다른 레이아웃에 맞게 자동으로 변형되지 않는다. 

일반적인 표준 이미지 크기 조정은 충분하지 않다. 자르기는 이미지 주변부에서만 픽셀을 제거할 수 있기 때문에 제한적이다. 
geometric constraints뿐만 아니라 이미지 콘텐츠까지 고려해야만 보다 효과적인 크기 조정을 수행할 수 있다.

Seam-carving: a simple image operator

Seam-carving은 픽셀의 중요성을 정의하는데 energy function을 사용한다. 이미지 축소에서는 낮은 에너지를 가진 픽셀들을 많이 제거하고, 높은 에너지를 가진 픽셀들은 더 적게 제거한다. 이미지 확대의 경우 seam insertion을 통해 원본 이미지 콘텐츠와 인위적으로 삽입된 픽셀 간의 (비율)균형을 유지한다.

Seam carving의 적용에 대해서도 서술하겠다
: aspect ratio change, image retargeting, image content enhancement, object removal

추가적으로 multi-size image도 정의한다
→ content-aware한 image들의 사이즈를 계속 변경할 수 있다

our main contributions
- Define seam carving and present its properties.
- Present algorithm for image enlarging using seam insertions.
- Use seams for content-aware image size manipulations.
- Define multi-size images for continuous image retargeting

# 2. Background

# 3. The Operator

목표: content-aware resizing

제거할 픽셀들을 어떻게 선택할까?
→배경과 섞인 unnoticeable piexel들 제거하기
(=낮은 에너지를 가진 픽셀들을 제거하겠다)

simple energy function

![fig1](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/0e3b3d39-9668-4486-af11-0f61956160b5)

이미지 넓이 줄이고 싶을 때

i) optimal strategy(낮은 에너지의 픽셀부터 제거) (f)
→ 직사각형 모양 파괴시킴

ii) 모든 행에서 동일한 수의 저에너지 픽셀을 제거 (e)
→ zigzag effect

iii) auto-cropping (b)
→ contains highest energy

iv) remove whole columns with the lowest energy (c)

![fig22](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/437c540f-5c76-4aa1-a64f-126ddfb5ff74)

픽셀을 삭제하는 것보다 이미지 content를 유지할 수 있는 resizing operator가 필요하다!


let I be an n×m image and define a vertical seam to be:
![fig2](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/b21492b9-5626-4939-97c9-f80aa0ae2bc3)


if y is a mapping y : [1,...,m] → [1,...,n], then a horizontal seam is:
![fig23](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/291c6d46-2b18-4a99-ab1f-4b4632999d54)


## 3.1 Energy Preservation Measure

content-aware resizing은 <낮은 에너지 픽셀들을 제거하고 높은 에너지 픽셀들을 유지시키면서> 전체 에너지 average를 증가시켜야 한다.
![fig24](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/3cbd8c9d-62fb-4a9c-a133-782c89c5bf05)

Seam carving이 좋은 balance를 보여준다.(energy preservation+visual coherency)

## 3.2 Image Energy Functions

![fig32](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/25a7fc73-d927-40ca-9a69-94d07738c65e)

이 연구에서는 이미지 크기 조정을 위해 다양한 이미지 importance 측정 방법과 에너지 함수를 실험하고 비교하였다. 특정 함수가 모든 이미지에 대해 최적으로 작동하지 않지만 일반적으로 이미지 크기를 조정하는 데 사용할 수 있음을 발견했다. 상황에 따라 e1 또는 eHoG가 잘 작동하는 것으로 나타났다.

# 4. Discrete Image Resizing

## 4.1 Aspect Ratio Change (종횡 비 변화)

만약 n*m 크기의 이미지 I를 n*m’로 변경하고 싶을 때, c = m-m’

![fig5](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/48594375-5083-4e18-8351-7666b92417a2)

simple scaling: c만큼 vertical seams 제거

seam removal operation은 중요한 부분 바꾸지 않는다

![fig6](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/3332e2c0-798e-4c39-8092-30e87dc0173f)

행 수를 m/m’만큼 늘리기 → 이미지에서 어떠한 정보도 제거하지 않아야 한다

## 4.2 Retargeting with Optimal Seams-Order

 n × m의 이미지 I will be retargeted to size n’ × m’ ( m’ < m, n’ < n 라고 가정)

optimal order 제시

…………………….

Figure 7 shows an example of different retargeting strategies on an image.

![fig7](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/baa304f4-1bdb-4197-be1a-d71df822000c)
## 4.3 Image Enlarging

이미지를 확대하기 위해서 시간변화의 ‘inversion’을 근사하고, 새로운 인공적인 seam을 이미지에 삽입한다.

![fig77](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/cb614932-1850-4b81-a06e-c5fd5a1c89e2)
we compute the optimal vertical (horizontal) seam S on I and duplicate the pixels of S by averaging them with their left and right neighbors.

그 결과 (b) create a stretching artifact by choosing the same seam

(c) we find the first k seams for removal, and duplicate them in order to arrive at I^(−k)

(d) achieves the desired 50% enlargement 

(e)  Duplicating all the seams in an image is equivalent to standard scaling
→ essentially guarding the important content from being stretched

(f) Using two steps of seam insertions of 50%

## 4.4 Content Amplification

seam carving은 이미지의 크기를 유지하면서 이미지의 content를 확대하는 데 사용될 수 있다: achieved by combining seam carving and scaling.

we first use standard scaling to enlarge the image and only then apply seam carving on the larger image to carve the image back to its original size.

![fig9](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/5cc67929-f3bd-4b69-a52f-2a7779b28e23)

## 4.5 Seam Carving in the gradient domain

![fig10](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/47423420-10c9-4657-8777-17f8402081c3)

## 4.6 Object Removal

사용자가 지우고 싶은 이미지를 mark하면 해당 seam들이 삭제된다 

![fig11](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/7e74bb50-1b0f-4826-8d8f-cad03c318082)

to regain the original size of the image, seam insertion could be employed on
the resulting (smaller) image

![fig12](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/a46eb10f-ce83-402a-ac92-b774eb71bd5c)

왼쪽 아래 사진 보면 연두색 신발 사라짐
+원래 크기로 확대되었다(seam insertion할 수도 있음)

# 5. Multi-size Images

사용자가 항상 타겟 이미지 사이즈를 아는 것은 아니다

사용자는 다양한 타겟 크기를 시도해보고 자신의 필요에 가장 적합한 크기를 선택할 수 있다.

평균적으로 400×500 크기의 이미지를 100×100으로 retarget하는 데 약 2.2초가 걸린다. 그러나 수십, 수백 개의 seam들를 실시간으로 계산하는 것은 어려운 작업이다. 

we present a representation of multi-size images 
(that encodes, for an image of size (m×n), an entire range of retargeting sizes from 1×1 to m×n and even further to N’ × M’ , when N’ > n,M’> m.)

이 내용은 메모리 사용량이 매우 적고 전처리 단계를 몇 초 만에 계산할 수 있으며 사용자가 실시간으로 이미지를 연속적으로 retarget할 수 있도록 해준다.

![fig13](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/5c7231ee-9b35-4ef5-b8cc-96ded6a15d05)

# 6. Limitations

seam carving 방식이 모든 이미지에서 자동적으로 동작하지 않는다.

seam carving의 두 개의 한계점

- 이미지의 content amount
less important pixel이 없으면?? resizing 잘 못함
- 이미지 content의 형태
중요한 부분을 건너뛸 수도 있다

![fig16](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/f60fdbd6-3a46-46e8-a4cb-cba372930d43)

# 7. Conclusions and Future Work

We presented an operator for content-aware resizing of images using seam carving.

We would like to extend our approach to other domains

- resizing of video
- define more robust multi-size image
- find better way to combine horizontal and vertical seams in multi-size images
