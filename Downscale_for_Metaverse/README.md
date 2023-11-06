down_resolution.py: 연구를 진행하며 구현한 기본 코드

특정한 값으로 파라미터 주는 내용 있음

#추가할 내용
- ffmpeg 오픈된 라이브러리인지 확인해보기 - 문제 없을 듯
- '1920'를 변수로 바꾸기 
- size를 미리 정의해서 (HD를 위한 downscaling은 이미 있다고 가정 등) FullHD, UHD 를 대상으로 한 코드
- 변수 이름도 miv_width, miv_height 등, target 비율 조건도 추가하기(4:3, 21:9 등) - 일반화된 변수로
-  우리가 타게팅 하는 해상도 이상 일때는 실행하고, 그 이하이면 그냥 return 시킨다. (execption code 추가해서)
ex) source image 너무 작으면 error 발생시키기

"metaverse용 초고해상도 영상 resizing하는 코드"
- 필요성:MIV는 데이터 너무 커서 resizing 필요하다. 

*input 파일명 함수 따로 추가하기
