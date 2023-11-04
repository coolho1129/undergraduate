import os

import numpy as np
import skimage.color
import skimage.io
import torch

def directory_parsing(dirpath):
    file_list = []

    for root, dirs, files in os.walk(dirpath):
        for file in files:
            file_list.append(os.path.join(root, file))
    return file_list


def make_output_path(input_path):
    file_path = input_path.split('\\')[-3] 
    file_name = input_path.split('\\')[-1]
    path = f'out/{file_path}/{file_name}'
    return path

def find_mask_path(input_path):
    file_path = input_path.split('\\')[-4] + '\\' +input_path.split('\\')[-3]
    file_name = input_path.split('\\')[-1]
    file_name = file_name.split('.')[0] + '.png'
    path = f'{file_path}/masks/{file_name}'
    return path


def to_numpy(tensor: torch.Tensor, clone=True) -> np.ndarray:
    tensor = tensor.detach()
    tensor = tensor.clone() if clone else tensor
    return tensor.cpu().numpy()


def imread(path: str) -> torch.Tensor:
    image = skimage.io.imread(path)
    if image.ndim == 2:
        image = skimage.color.gray2rgb(image)
    image = torch.tensor(image, dtype=torch.float32)
    image = image.permute(2, 0, 1)
    return image / 255


def imwrite(path: str, image: torch.Tensor) -> None:
    os.makedirs(os.path.dirname(path), exist_ok=True)
    image = image.permute(1, 2, 0)
    image = to_numpy((255 * image).clamp(0, 255).to(dtype=torch.uint8))
    return skimage.io.imsave(path, image)


def mask_read(mask_path: str) -> torch.Tensor:
    mask = imread(mask_path)
    if mask.ndim == 3:
        mask = mask[0]
    return (mask > 0.5)
