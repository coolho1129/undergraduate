import ffmpeg
import os

#pip install ffmpeg-python 
#ffmpeg 설치 -> 환경변수 설정해주면 됨. 
#MIV_mp4 폴더에서 texture 이름 통일시키기
PATH='./MIV_mp4'
#os.mkdir('resized_MIV')

file_list=os.listdir(PATH)
print(file_list)

for f in file_list:
    texture_path=PATH+'/'+f+'/'+'texture'
    os.mkdir('./resized_MIV/'+f+'_downscale')
    print(texture_path)
    texture_video_list=os.listdir(texture_path)
    for tv in texture_video_list:
        v_path=texture_path+'/'+tv
        ffmpeg.input(v_path).output(('./resized_MIV/'+f+'_downsclae/'+tv),crf=45).run()
