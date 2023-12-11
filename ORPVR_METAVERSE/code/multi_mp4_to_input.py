import os
import cv2
import argparse

cap = cv2.VideoCapture()

# MIV_mp4 폴더에서 각 폴더 경로 args로 받아서 mp4->input
# def get_args():
#     parser = argparse.ArgumentParser()
#     parser.add_argument("video", type=str, default='', help="input video name")
#     return parser.parse_args()

# if __name__ == '__main__':
#     miv = get_args().video
#     if not os.path.exists(miv):
#         print("video does not exist")
#         exit(1)
#     highdir=os.path.basename(miv).split('.')[0]
#     lowdir=os.listdir(miv)
#     for low in lowdir:
#         dep_tex_path=miv+'/'+low+'/'
#         video_list=os.listdir(dep_tex_path)
#         for v in video_list:
#             video_path=dep_tex_path+v

#             vidname = os.path.basename(video_path).split('.')[0]
#             dstdir = os.path.join('rawdataset', highdir,low,vidname)
#             os.makedirs(dstdir)
#             cap = cv2.VideoCapture(video_path)
#             vidlength = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
#             l = len(str(vidlength - 1))
#             for i in range(vidlength):
#                 ret, frame = cap.read()
#                 if not ret:
#                     break
#                 cv2.imwrite(os.path.join(dstdir,str(i).rjust(l,'0')+'.jpg'), frame)
#             print(f"total {vidlength} frames saved to {dstdir}")

#비디오 resize 한 후 resized_MIV 폴더에서 비디오 가져오는 코드 args = riszed_MIV
def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("video", type=str, default='', help="input video name")
    return parser.parse_args()

if __name__ == '__main__':
    vidpath = get_args().video
    folder_list=os.listdir(vidpath)
    if not os.path.exists(vidpath):
        print("video does not exist")
        exit(1)
    
    for f in folder_list:
        video_list=os.listdir(vidpath+'/'+f)
        for v in video_list:
            dstdir = os.path.join('rawdataset',f, v)
            os.makedirs(dstdir)

            video_path=os.path.join(vidpath,f,v)
            cap = cv2.VideoCapture(video_path)
            vidlength = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
            l = len(str(vidlength - 1))
            for i in range(vidlength):
                ret, frame = cap.read()
                if not ret:
                    break
                cv2.imwrite(os.path.join(dstdir,str(i).rjust(l,'0')+'.jpg'), frame)
            print(f"total {vidlength} frames saved to {dstdir}")
