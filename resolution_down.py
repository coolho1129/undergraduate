import ffmpeg
import os
import sys
def resize(src,mode):
    
    # 해상도 변경 모드 설정
    resolution={'FHD':'scale=1920:1080','HD':'scale=1280:720'}
    #print(resolution[mode])
    
    #생성파일 저장 폴더 생성
    dstsrc=src.replace("MIV_mp4", "MIV_mp4_resize")
    dstsrc=src.replace(dstsrc.split("\\")[1],dstsrc.split("\\")[1]+"_resize")
    dstdir=dstsrc.replace(dstsrc.split("\\")[-1],"")
    os.makedirs(dstdir,exist_ok=True)
    
    # 입력 및 출력 파일 경로 설정
    input_file = src
    output_file = os.path.join(dstsrc)
        
    # 입력 동영상 스트림 생성
    input_stream = ffmpeg.input(input_file)

    # 비디오 스트림을 해상도 변경
    output_stream = ffmpeg.output(input_stream, output_file, vf=resolution[mode])

    # 오디오 스트림을 복사
    output_stream = ffmpeg.output(output_stream, vf=resolution[mode], acodec='copy')

    # FFmpeg 명령 실행
    ffmpeg.run(output_stream)
    
  
def main(mivmp4_src):
    mode="FHD"
    argc=len(sys.argv)
    if(argc==3 and sys.argv[2].upper()=='HD'):
        mode='HD'
    if(argc>3 or argc<2):
        print("아래와 같은 형태로 인자를 입력해주세요(mode:FHD or HD)")
        print("python resolution_down.py src mode")
        exit(-1)
    
    high_dir=os.listdir(mivmp4_src)
    for high in high_dir:
        high_path=os.path.join(mivmp4_src,high)
        low_dir=os.listdir(high_path)
        for low in low_dir:
            low_path=os.path.join(high_path,low)
            videos=os.listdir(low_path)
            for video in videos:
                video_path=os.path.join(low_path,video)
                resize(video_path,mode)

if __name__ == '__main__':
    #print(sys.argv)
    main(sys.argv[1])
