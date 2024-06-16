
# 프로그램 명세

## Down_resolution

program.py 라고 가정함
사용방법: python down_resolution.py [-h] [-input INPUT] [-output OUTPUT] [-mode {FHD,HD,SD}] [-ratio RATIO]
python program.py [input_media]

![1](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/e4c6e515-4a04-470a-b86c-89d8510195f0)

![2](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/0ff83f0f-6d54-40bd-b49f-d799c0773445)


1. input
    - 이미지 ( .jpg / .jpeg / .png )
    - 동영상 ( .mp4 / .avi )
2. option
    1. 비율
        - 비율 그대로 조정 (default)
        - 사용자가 원하는 비율로 조정 -ratio ( -r) height : width
    2. 도움말 ( -help / -h )
        - 도움말 확인
    3. 해상도 선택 ( -mode / -m )
        - Full-HD : N x 1080 ( -mode FHD )
        - HD : N x 720 ( HD )
        - SD : N x 480 ( SD )
    4. output 경로 지정 (-output / -o)
        - defalut 현재 파일을 실행중인 디렉토리
        - 사용자가 원하는 위치 지정 -output (-o) 경로
       <img src="https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/1eae0fec-19f2-434f-8fe9-aeab8f8226ee" width="450" height="200">


3. output

    programname / [input_media_name_output.~~]

### Usecase

![downscale_usecase](https://github.com/coolho1129/Metaverse-Background-Research/assets/111948424/aeab0615-7251-44e3-95ba-25d62230945f)
