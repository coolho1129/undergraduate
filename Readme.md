# 2023-2 COMP0322 Database Team8
경북대학교 컴퓨터학부 데이터베이스 팀프로젝트 </br>
Collaborator: 김찬호, 송혜경, 하재현

## Project Description
<!--✔ 프로젝트명--!>
<b>프로젝트명: 약++</b></br></br>

<!--✔ 어떤 프로젝트인지 소개 -->
<b>목적: 사용자들이 일반 의약품을 올바르게 활용하고 남용하지 않도록 돕기 위해 일반의약품 검색 및 리뷰 서비스를 기획하였다.</b></br>

<b>차별성: 사용자들이 직접 약 사용 후기를 작성하는 환경을 제공하여 복용 경험을 손쉽게 공유할 수 있는 플랫폼을 구축하였다.</br></br>

<b>사용된 기술: spring-boot, oracle DB, JSP</br></br>
## Getting Started
To get started with this project, you will need to have the following installed on your local machine:
```
✔ JDK 17
✔ Apache Maven 3.9.5
 
```
To build and run the project, follow these steps:
1. Clone the repository: git clone https://github.com/sosschs9/2023_Database.git
2. Navigate to the project directory: cd 2023_Database
3. Build the project: mvn clean install
4. Run the project: mvn spring-boot:run
5. Access: Accessing via localhost:8080
   
***You must include application.properties file in src/main/resources***

## Feature Description
```
1. 회원가입/ 로그인
   1.1 회원가입
       1.1.1 ID, Password, 이름, 생년월일, 성별 입력
   1.2 로그인
       1.2.1 아이디, 패스워드 입력

2. 사용자
   2.1 검색
       2.1.1 각 항목에 검색어를 입력한 후 검색 버튼을 클릭하면 해당 조건에 맞는 내용을 검색
             (항목: 제품명, 성분명, 회사명, 효능효과, 진료분과, 가격)
       2.1.2 검색된 약을 한 번 더 누르면 약 상세 페이지로 이동

       2.2.1 사용자는 많이 검색된 상위 5개의 약을 확인할 수 있음.

   2.2 리뷰
     2.1 리뷰 작성
         2.1.1 회원가입을 한 사용자는 로그인 이후 약에 대해 평점을 매기고 리뷰를 작성
     2.2 리뷰 확인
         2.2.1 사용자는 최신 날짜순으로 정렬된 리뷰에서 리뷰어의 이름, 의약품명, 평점, 평가 내용, 작성 날짜를 확인
   
```

## Project Result
✔ 시연영상 삽입
