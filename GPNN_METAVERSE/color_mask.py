# import cv2
# import numpy as np
# from collections import Counter

# # 이미지와 마스크 로드
# image = cv2.imread('image.jpg')
# mask = cv2.imread('mask.jpg', 0)  # 흑백 마스크로 로드

# # 마스킹된 영역의 색상 분석
# masked_pixels = image[np.where(mask != 0)]
# colors, counts = np.unique(masked_pixels, axis=0, return_counts=True)

# # 주변에서 가장 많이 사용된 색상 찾기
# most_common_color = colors[np.argmax(counts)]

# # 마스킹된 영역을 주변에서 가장 많이 사용된 색상으로 채우기
# filled_image = image.copy()
# filled_image[np.where(mask != 0)] = most_common_color
# cv2.imwrite("ma/output.jpg", filled_image)

# # 결과 이미지 표시
# cv2.imshow('Filled Image', filled_image)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

# import cv2
# import numpy as np

# # 이미지와 마스크 로드
# image = cv2.imread('image.jpg')
# mask = cv2.imread('mask.jpg', 0)  # 흑백 마스크로 로드

# # 배경 색상 추출
# background_color = np.mean(image[np.where(mask == 0)], axis=0)

# # 마스킹된 영역을 배경 색상에 맞게 채우기
# filled_image = image.copy()

# for i in range(image.shape[0]):
#     for j in range(image.shape[1]):
#         if mask[i, j] != 0:
#             filled_image[i, j] = background_color

# # 결과 이미지 표시
# cv2.imshow('Filled Image', filled_image)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

import cv2
import numpy as np

# 이미지와 마스크 로드
image = cv2.imread('image.jpg')
mask = cv2.imread('mask.jpg', 0)  # 흑백 마스크로 로드

# 이미지의 높이, 너비 가져오기
height, width, _ = image.shape

# 이미지를 세 개의 수평 영역으로 나누기
third_height = height // 3

# 각 영역의 배경 색상 추출
upper_background_color = np.mean(image[:third_height, :, :], axis=(0, 1))
middle_background_color = np.mean(image[third_height:2*third_height, :, :], axis=(0, 1))
lower_background_color = np.mean(image[2*third_height:, :, :], axis=(0, 1))

# 마스킹된 영역을 수평 영역의 배경 색상에 맞게 채우기
filled_image = image.copy()

for i in range(height):
    for j in range(width):
        if mask[i, j] != 0:
            if i < third_height:
                filled_image[i, j] = upper_background_color
            elif i < 2*third_height:
                filled_image[i, j] = middle_background_color
            else:
                filled_image[i, j] = lower_background_color

# 결과 이미지 표시
cv2.imshow('Filled Image', filled_image)
cv2.waitKey(0)
cv2.destroyAllWindows()


# import cv2
# import numpy as np

# # 이미지와 마스크 로드
# image = cv2.imread('image.jpg')
# mask = cv2.imread('mask.jpg', 0)  # 흑백 마스크로 로드

# # 이미지의 높이, 너비 가져오기
# height, width, _ = image.shape

# # 이미지를 네 개의 영역으로 나누기
# third_height = height // 3
# third_width = width // 3

# # 각 영역의 배경 색상 추출
# background_colors = []
# for i in range(3):
#     for j in range(3):
#         background_color = np.mean(image[i*third_height:(i+1)*third_height, j*third_width:(j+1)*third_width, :], axis=(0, 1))
#         background_colors.append(background_color)

# # 마스킹된 영역을 각 영역의 배경 색상에 맞게 채우기
# filled_image = image.copy()

# for i in range(height):
#     for j in range(width):
#         if mask[i, j] != 0:
#             if i < third_height:
#                 if j < third_width:
#                     filled_image[i, j] = background_colors[0]
#                 elif j < 2*third_width:
#                     filled_image[i, j] = background_colors[1]
#                 else:
#                     filled_image[i, j] = background_colors[2]
#             elif i < 2*third_height:
#                 if j < third_width:
#                     filled_image[i, j] = background_colors[3]
#                 elif j < 2*third_width:
#                     filled_image[i, j] = background_colors[4]
#                 else:
#                     filled_image[i, j] = background_colors[5]
#             else:
#                 if j < third_width:
#                     filled_image[i, j] = background_colors[6]
#                 elif j < 2*third_width:
#                     filled_image[i, j] = background_colors[7]
#                 else:
#                     filled_image[i, j] = background_colors[8]

# # 결과 이미지 표시
# cv2.imshow('Filled Image', filled_image)
# cv2.waitKey(0)
# cv2.destroyAllWindows()