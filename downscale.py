import ffmpeg
import os
PATH='C:/Users/USER/Desktop/Metaverse_Retargeting/MIV_mp4'
os.mkdir('resized_MIV')

file_list=os.listdir(PATH)
err=[]
for f in file_list:
    texture_path=os.path.join(PATH,f,'texture')
    texture_video_list=os.listdir(texture_path)
    for tv in texture_video_list:
        v_path=os.path.join(texture_video_list,tv)
        ffmpeg.input(v_path).output(os.path.join(PATH,'resized_MIV',f,tv),crf=45).run()


#ffmpeg.input("C:/Users/USER/Desktop/Metaverse_Retargeting/MIV_mp4/(C02)Cyberpunk/textures/v0_texture_2048x2048_yuv420p10le.mp4").output('C:/Users/USER/Desktop/Metaverse_Retargeting/resized_MIV/resize.mp4',crf=40).run()
