# 2023-2 COMP0322 Database Team8
경북대학교 컴퓨터학부 데이터베이스 팀프로젝트 </br>
Collaborator: 김찬호, 송혜경, 하재현

## Project Description
<b>✔ 프로젝트명:</b> 약++</br>
<b>✔ 목적:</b> 사용자들이 일반 의약품을 올바르게 활용하고 남용하지 않도록 돕기 위해 일반의약품 검색 및 리뷰 서비스를 기획하였다.</br>
<b>✔ 차별성:</b> 사용자들이 직접 약 사용 후기를 작성하는 환경을 제공하여 복용 경험을 손쉽게 공유할 수 있는 플랫폼을 구축하였다.</br>
<b>✔ 사용된 기술:</b> Springboot, JPA, Oracle DB, HTML, Tailwindcss, JS</br></br>

## Getting Started
### 개발환경
```
- windows 10, 11
- oracle 19c
- oracle SQL Developer
- JDK 17
- Apache Maven 3.9.5
```
### 실행방법
1. oracle 'team8' 스키마 생성
```
sqlplus sys/oracle as sysdba
CREATE USER team8 IDENTIFIED by comp322;
GRANT ALL PRIVILEGES to team8 IDENTIFIED BY comp322;
```
2. 테이블 생성 및 데이터 삽입
```
Team8-Phase2-1.sql의 create문 실행
commit;
Team8-Phase2-2.sql의 insert문 실행
commit;
Team8-Phase2-1.sql의 alter문 실행
commit;
```
3. Team8-Phase4-view.sql 실행
4. Clone the repository: git clone https://github.com/sosschs9/2023_Database.git
5. Navigate to the project directory: cd 2023_Database
6. Build the project: mvn clean install
7. Run the project: mvn spring-boot:run
8. Access: Accessing via localhost:8080/main
   
***You must include application.properties file in src/main/resources***
</br>

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
[시연영상 바로가기](https://www.youtube.com/watch?v=stEhlrn09rg)
