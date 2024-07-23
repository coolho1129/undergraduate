## Abstract

“Internal GAN”(InGAN) 제안; an image specific GAN
- fully unsupervised
- 단 한 장의 input 이미지 만으로 학습
- 이미지 자체 조각의 분포를 유지하면서 다양한 크기나 모양의 이미지를 생성할 수 있다

# 1. Introduction

 각각의 이미지는 본연의 독창적인 특징을 가지고 있다. 이 논문에서는 한 이미지를 가지고 “same DNA”를 가진 새로운 이미지를 만드는 내용을 다룬다
*same DNA: with the same internal patch distribution as the input image

 이 기술의 필요성
input image를 가지고 새로운 image를 만들 때, 내부의 주요 요소들이 왜곡되지 않았으면 한다. 사진의 모양이나 크기를 달리 해도 사진의 요소가 자연스럽게 생성/수정/유지 되면 좋겠다.

![image1](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/fda1fdc7-d1db-4c61-aaf1-2c0013bbb344)
![image2](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/7a1baa5d-517f-42fb-b217-b0ed41b6377c)

 위 단락 내용을 가능하게 하는 핵심 기술: Distribution-matching
Distribution-matching은 same DNA를 가진 새로운 target image를 다른 사이즈/모양으로 생성하게 해준다. 

 선행된 기술: Bidirectional-Similarity of Simakov
이것은 Visual Coherence(contain only patches from the input image), Visual Completeness(contain only patches from the target)를 지키는데 제약이 있다. 
우리의 ‘Distribution Matching”은 이 제약들을 뛰어 넘을 것이다.

 일반적으로 GAN은 많은 데이터셋들을 학습한 이미지 생성기이다. 그래서 결과 이미지의 출처를 모른다. 반면에 InGAN은 한 이미지에 특화된 GAN이다. 추가적으로 Retargeting도 한다.

 InGAN를 사용하면 이론적으로 Coherence, Completeness 해결한다. 하지만, 실제로 Completeness가 종종 해결되지 않는 모습을 보인다. 그래서 Encoder-Encoder 구조(||G (G (x)) − x ||)를 사용해 보겠다.

 이전에 연구된 GAN모델은 대부분 map noise to image 하는 unconditional GAN이다. InGAN모델은 map images to images인 conditional GAN이다. 추가적으로 InGAN은 single unified frame도 제공하겠다.

several contributions

- define distribution-matching
- InGAN produce outputs with only one-time trained
- InGAN is the first to train a GAN on a single natural image
- Encoder-Encoder 구조 만들어봄

# 2. Method

## 2.1 Overview

InGAN: image-conditional GAN
![image3](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/f62a5d3c-320c-4c75-84c8-188effab307b)
generator G 사용 → discriminator D → G 재사용 (for decoding/reconstructing the input given the output)

이 모델로 두 가지 달성할 것이다.

- matching distributions
- localization

x: given an input image
T: geometric transformation (size/shape/aspect-ratio )
G synthesizes a new image y

adopt LSGAN variant

The discriminator D and *L*GAN encourage matching the patch distribution of y = G (x; T) to that of x.

실제로 *L*GAN만 사용하면 coherent (O) complete (X)

→ G + reuse G : mode collapse 피하고 completeness 유지하기 위해

InGAN의 최종 loss function: 
![image8](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/84f20273-1a62-4c00-b532-f06f4be80d87)

The architecture is locally connected rather than fully-connected (in particular, it is convolutional).

## 2.2 Shape-flexible Generator
![image4](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/3e58b108-a66b-4b88-a192-1d5348d44206)

Making the transformation layer parameter-free allows training G once to transform x to any size, shape or aspect ratio at test time.

## 2.3 Multi-scale Patch Discriminator
![image5](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/8297aa8e-22c2-486e-8d66-57e799c28376)

use a fully-convolutional patch discriminator D
→ 따라서 D는 합성된 전체 이미지를 평가하는 대신 패치 분포와 얼마나 잘 일치하는지에 따라 각 패치를 평가한다.

uses a multi-scale D
→matches the patch distribution over a range of patch sizes, capturing both fine-grained details as well as coarse structures in the image. + rather simple

3문단 추가바랍니다,,

## 2.4 Generator Invertibility

“Encoder-Encoder” architecture

더 나은 completeness를 달성하기 위해, InGAN은 output image y 로 input image x를 재생성한다. → y에서 시각적 정보를 잃었는지 확인할 수 있다.

# 3. Implementation Details

1. use ADAM optimizer and a linearly decaying learning rate
2. 안정성을 위해서
- spectral normalization (used both in the discriminator and the generator for all layers except the last one.)
- batch normalization(used in most conv-blocks) 
메커니즘 사용
- add uniform noise in the range of [0, 1/255] to the real examples before feeding them to the discriminator.
3. InGAN requries around 20k-75k iterations of gradient descent in order to obtatin appealing results.

# 4. A Unified Framework for Multiple Tasks

InGAN provides a variety of capabilities and can be applied to multiple tasks.

InGAN applies to a continuum from pure textures to natural images, in a single framework.
![image6](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/5fdc0c24-b4dd-42b7-a39d-ee6b2454aa34)

InGAN has no semantic information about “objects” or “scenes”, it only models the multiscale patch distribution of the input image.

Project’s web page에 더 많은 예시 있음

InGAN provides a single unified framework for variety of tasks.

Texture Synthesis: InGAN can handle both single and multi-texture synthesis, thanks to its multiscale discriminator.

Natural Image Retargeting: Summary and Expansion
displaying a natural image on a different display size, smaller or larger, often with a different aspect ratio.

There are several different notions of “image retargeting”. Ex) Seam-carving

Other methods aim at preserving local sizes/aspect-ratios of all image elements. while changing the global size/aspectratio of the image. They cater both Summarization and Expansion.
- InGAN belongs to this family of methods.

InGAN synthesizes a plethora of new target images of different shapes with a single trained network.

Image Retargetig to Non-rectangular Shapes is also possible with InGAN.

# 5. Ablation Study and Limitations

ablation study to verify the importance of

- “encoder-encoder” 구조
- multiscale discriminator D
→ maintains fine details and coarse structures.

Limitations
- InGAN은 비지도 학습이다→ 객체나 배경에 대한 의미적인 이해도가 없다.
- InGAN은 때때로 웃기거나 부자연스러운 결과를 생성한다.
![image7](https://github.com/coolho1129/Metaverse-Background-Research/assets/75716291/6f286494-8923-41da-8283-61e99156ff11)

