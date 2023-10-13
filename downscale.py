import ffmpeg
import os

#pip install ffmpeg-python 
#ffmpeg 설치 -> 환경변수 설정해주면 됨. 
#MIV_mp4 폴더에서 texture 이름 통일시키기
PATH='C:/Users/USER/Desktop/metaverse_retargeting/MIV_mp4'
#os.mkdir('resized_MIV')

file_list=os.listdir(PATH)
err=[]
for f in file_list:
    texture_path=PATH+'/'+f+'/'+'texture'
    os.mkdir('C:/Users/USER/Desktop/metaverse_retargeting/resized_MIV/'+f)
    print(texture_path)
    texture_video_list=os.listdir(texture_path)
    for tv in texture_video_list:
        v_path=texture_path+'/'+tv

        ffmpeg.input(v_path).output(('C:/Users/USER/Desktop/metaverse_retargeting/resized_MIV/'+f+'/'+tv),crf=45).run()


#ffmpeg.input("C:/Users/USER/Desktop/Metaverse_Retargeting/MIV_mp4/(C02)Cyberpunk/textures/v0_texture_2048x2048_yuv420p10le.mp4").output('C:/Users/USER/Desktop/Metaverse_Retargeting/resized_MIV/resize.mp4',crf=40).run()
