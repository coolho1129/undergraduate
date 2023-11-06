import ffmpeg
import os
import sys
import cv2
from PIL import Image

def video_resize(src,mode):
    # 비디오 파일 열기
    cap = cv2.VideoCapture(src)

    # 비디오 파일 정보 얻기
    width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))  # 비디오 프레임의 너비
    height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))  # 비디오 프레임의 높이
    print('현재 해상도: {} x {}'.format(width, height))
    resolution=""
    if mode=='FHD':
        resolution='scale=1920:'+str(int((height/width)*1920))
    else:
        resolution='scale=1280:'+str(int((height/width)*1280))
    print('변경 해상도: {}'.format(resolution))
    
    
    #생성파일 저장 폴더 생성
    folder=src.split("\\")[0]
    dstfolder=folder+'_resize'
    dstsrc=src.replace(folder, dstfolder)
    dstsrc=src.replace(dstsrc.split("\\")[1],dstsrc.split("\\")[1]+"_resize")
    dstdir=dstsrc.replace(dstsrc.split("\\")[-1],"")
    os.makedirs(dstdir,exist_ok=True)
    
    # 입력 및 출력 파일 경로 설정
    input_file = src
    output_file = os.path.join(dstsrc)
        
    # 입력 동영상 스트림 생성
    input_stream = ffmpeg.input(input_file)
    output_stream = ffmpeg.output(input_stream, output_file, vf=resolution, vcodec='libx264',acodec='copy')

    # FFmpeg 명령 실행
    ffmpeg.run(output_stream)
    print('video downscale complete')

def img_resize(src):
    #생성파일 저장 폴더 생성
    folder=src.split("\\")[0]
    dstfolder=folder+'_resize'
    dstsrc=src.replace(folder, dstfolder)
    dstsrc=src.replace(dstsrc.split("\\")[1],dstsrc.split("\\")[1]+"_resize")
    dstdir=dstsrc.replace(dstsrc.split("\\")[-1],"")
    os.makedirs(dstdir,exist_ok=True)
    
    # 입력 및 출력 파일 경로 설정
    input_file = src
    output_file = os.path.join(dstsrc)
    # 이미지 불러오기
    input_image = Image.open(input_file)

    # 원하는 해상도로 이미지 크기 조정
    new_width = 1280
    new_height = 720
    resized_image = input_image.resize((new_width, new_height), Image.ANTIALIAS)

    # 조정된 이미지 저장
    resized_image.save(output_file)
    print('image resizing complete')
    
  
def main(src):
    mode="FHD"
    argc=len(sys.argv)
    if(argc==3 and sys.argv[2].upper()=='HD'):
        mode='HD'
    if(argc>3 or argc<2):
        print("아래와 같은 형태로 인자를 입력해주세요(mode:FHD or HD)")
        print("python resolution_down.py src mode")
        exit(-1)
    
    high_dir=os.listdir(src)
    for high in high_dir:
        high_path=os.path.join(src,high)
        low_dir=os.listdir(high_path)
        for low in low_dir:
            low_path=os.path.join(high_path,low)
            files=os.listdir(low_path)
            for file in files:
                file_path=os.path.join(low_path,file)
                if file.lower().endswith('.jpg') or file.lower().endswith('.png'):
                    img_resize(file_path)
                elif file.lower().endswith('.mp4'):
                    video_resize(file_path,mode)

if __name__ == '__main__':
    #print(sys.argv)
    main(sys.argv[1])
