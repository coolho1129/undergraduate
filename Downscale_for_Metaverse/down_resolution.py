import ffmpeg
import os
import sys
import cv2
import argparse

def downscale(input,output,mode,ratio):
    video_extension=('.mp4','.avi')
    image_extension=('.jpg','.png','.jpeg')
    _,file_extension= os.path.splitext(input)
    
    if file_extension in image_extension:
        print('확장자: '+file_extension)
        print('이미지 파일입니다.')
        img_downscale(input,output,mode,ratio)

    elif file_extension in video_extension:
        print('확장자: '+file_extension)
        print('비디오 파일입니다.')
        video_downscale(input,output,mode,ratio)
    
    else:
        print(file_extension+'은(는) 지원하지 않는 파일 형식입니다.')
        print('아래의 확장자를 따르는 이미지 또는 비디오 파일을 입력해주세요.')
        print('이미지 확장자: .png, .jpg, .jpeg')
        print('비디어 확장자: .mp4','.avi')
        sys.exit()  
        
def set_output(input,output):
    file_path = os.path.basename(input)
    file_name, file_extension = os.path.splitext(file_path)
    file_name = file_name + '_resized' + file_extension
    output_file = os.path.join(output, file_name)
    return output_file

def set_height(mode):
    modes={'FHD':1080,'HD':720,'SD':480}
    if mode not in modes:
        print('지원하지 않는 해상도 모드입니다. FHD, HD, SD 중 하나를 입력해주세요.')
        sys.exit()
    return modes[mode]
    
def set_ratio(ratio,width,height,mode):
    if not ratio:
        ratio=str(width)+':'+str(height)
    
    rationum=ratio.split(":")
    width_r= int(rationum[0])
    height_r= int(rationum[1])
    new_height=set_height(mode)
    new_width = int(new_height*width_r/height_r)
    if width<new_width:
        print('너비가 {}보다 작습니다. 다른 비율을 입력해주세요.'.format(new_width))
        sys.exit()
    elif height<new_height:
        print('높이가 {}보다 작습니다. 다른 비율을 입력해주세요.'.format(new_height))
        sys.exit()
    print('변경 해상도: {} x {}'.format(new_width, new_height))
    
    return new_width, new_height

def video_downscale(input,output,mode='FHD',ratio=None):
    
    # 입력 및 출력 파일 경로 설정
    input_file = input
    output_file = set_output(input,output)
 
    # 비디오 파일 열기
    cap = cv2.VideoCapture(input)

    # 비디오 파일 정보 얻기
    if cap.isOpened():
        width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))  # 비디오 프레임의 너비
        height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))  # 비디오 프레임의 높이
        print('현재 해상도: {} x {}'.format(width, height))
    else:
        print("비디오를 열 수 없습니다. 파일 경로 또는 코덱을 확인하세요.")
        sys.exit()
        
    if(width<600 or height<1080):
        print('해상도가 너무 작습니다. 너비가 600 이상이고 높이가 1080 이상의 해상도를 가진 파일을 입력해주세요.')
        sys.exit()

    # 해상도 변경
    new_width,new_height=set_ratio(ratio,width,height,mode)
    resolution='scale='+str(new_width)+':'+str(new_height)
    
    # 입력 동영상 스트림 생성
    input_stream = ffmpeg.input(input_file)
    output_stream = ffmpeg.output(input_stream, output_file, vf=resolution, vcodec='libx264',acodec='copy')

    # FFmpeg 명령 실행
    ffmpeg.run(output_stream)
    print('비디오 다운스케일 완료')
    

def img_downscale(input,output,mode,ratio):
    #저장 경로 설정
    output_file = set_output(input,output)
       
    # 이미지 불러오기
    input_image = cv2.imread(input)
    
    # 이미지 크기 구하기
    height, width, _ = input_image.shape
    
    print('현재 해상도: {} x {}'.format(width, height))
    
    if(width<600 or height<450):
        print('해상도가 너무 작습니다. 너비가 600 이상이고 높이가 450이상의 해상도를 가진 파일을 입력해주세요.')
        sys.exit()
    
    # 원하는 해상도로 이미지 크기 조정
    new_width,new_height=set_ratio(ratio,width,height,mode)
    resized_image = cv2.resize(input_image, (new_width, new_height), interpolation=cv2.INTER_LANCZOS4)

    # 이미지 저장
    cv2.imwrite(output_file, resized_image)
    print('이미지 다운스케일 완료')
    
def main():
    parser = argparse.ArgumentParser(description='명령줄에서 해상도 설정을 변경하는 스크립트')
    parser.add_argument('-input','-i', type=str, help='이미지 또는 비디오 파일 경로를 입력해주세요.')
    parser.add_argument('-output','-o', type=str, default='.', help='출력 파일 경로를 입력해주세요.')
    parser.add_argument('-mode','-m', choices=['FHD', 'HD', 'SD'], default='FHD', help='해상도 모드를 대문자로 입력해주세요. (기본값: FHD)')
    parser.add_argument('-ratio','-r', type=str, help='다운 스케일 비율 설정, N:M 형식으로 입력해주세요. (기본값: 원본 비율 유지)')
    
    args = parser.parse_args()
    if not args.input:
        print('usage: down_resolutionV3.py [-h] [-input INPUT] [-output OUTPUT] [-mode {FHD,HD,SD}] [-ratio RATIO]')
        print("-h 옵션을 사용하여 자세한 도움말을 확인하세요.")
        sys.exit()
    
    input = args.input
    output = args.output
    mode = args.mode
    ratio = args.ratio

    print(f'입력 파일 경로: {input}')
    print(f'출력 파일 저장 경로 :{output}')
    print(f'해상도 모드: {mode}')
    print(f'다운 스케일 비율: {ratio if ratio else "원본 비율을 유지합니다."}')    
    downscale(input,output,mode,ratio)

if __name__ == '__main__':
    main()
