import os
import cv2
import argparse

cap = cv2.VideoCapture()

# def get_args():
#     parser = argparse.ArgumentParser()
#     parser.add_argument("video", type=str, default='', help="input video name")
#     return parser.parse_args()

# if __name__ == '__main__':
#     vidpath = get_args().video
#     if not os.path.exists(vidpath):
#         print("video does not exist")
#         exit(1)
#     highdirname=os.path.basename(os.path.dirname((os.path.dirname(vidpath))))
#     #print(highdirname)
#     vidname = os.path.basename(vidpath).split('.')[0]
#     dstdir = os.path.join('rawdataset',highdirname, vidname)
#     os.makedirs(dstdir)
#     cap = cv2.VideoCapture(vidpath)
#     vidlength = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
#     l = len(str(vidlength - 1))
#     for i in range(vidlength):
#         ret, frame = cap.read()
#         if not ret:
#             break
#         cv2.imwrite(os.path.join(dstdir,str(i).rjust(l,'0')+'.jpg'), frame)
#     print(f"total {vidlength} frames saved to {dstdir}")

def get_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("video", type=str, default='', help="input video name")
    return parser.parse_args()

if __name__ == '__main__':
    miv = get_args().video
    if not os.path.exists(miv):
        print("video does not exist")
        exit(1)
    highdir=os.path.basename(miv).split('.')[0]
    lowdir=os.listdir(miv)
    for low in lowdir:
        dep_tex_path=miv+'/'+low+'/'
        video_list=os.listdir(dep_tex_path)
        for v in video_list:
            video_path=dep_tex_path+v

            vidname = os.path.basename(video_path).split('.')[0]
            dstdir = os.path.join('rawdataset', highdir,low,vidname)
            os.makedirs(dstdir)
            cap = cv2.VideoCapture(video_path)
            vidlength = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
            l = len(str(vidlength - 1))
            for i in range(vidlength):
                ret, frame = cap.read()
                if not ret:
                    break
                cv2.imwrite(os.path.join(dstdir,str(i).rjust(l,'0')+'.jpg'), frame)
            print(f"total {vidlength} frames saved to {dstdir}")