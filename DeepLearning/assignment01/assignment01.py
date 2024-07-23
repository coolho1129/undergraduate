from PIL import Image, ImageDraw, ImageFont
import os

imgpath = './coolho.jpg'
name = input("Name: ")
birth = input("Birth: ")
mbti = input("MBTI: ")
position = input("WaterMark Position(LU/LD/RU/RD): ")

def add_watermark(image_path, name, birth, mbti, position, output_path):

    image = Image.open(image_path)
    width, height = image.size

    draw = ImageDraw.Draw(image)
    text = f"{name}\n {birth}\n {mbti}"
    font = ImageFont.truetype("arial.ttf", 30)  

    bbox = draw.textbbox((0, 0), text, font=font)
    textwidth = bbox[2] - bbox[0]
    textheight = bbox[3] - bbox[1]

    
    x = 10 
    y = 10  

    if position == 'LD':
        y = height - textheight - 10
    elif position == 'RU':
        x = width - textwidth - 10
    elif position == 'RD':
        x = width - textwidth - 10
        y = height - textheight - 10


    draw.text((x, y), text, font=font, fill=(255, 255, 255))

  
    image.save(output_path)


add_watermark(imgpath, name, birth, mbti, position, f'watermarked_{position}_photo.jpg')
