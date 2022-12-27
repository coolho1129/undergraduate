# 2022 탁병철 컴퓨터 구조  과제1 RISC - V 계산기 

본 과제에서는 RISC-V 어셈블리 언어를 사용하여 아래의 요구조건을 만족하는 어셈블리 프로그램을 작성한다.

 

# 요구기능

프로그램을 실행하면 사용자의 입력을 받을 때까지 대기한다.

대기상태에서는 "# "이 표시된다. (스페이스 포함)

사용자는 입력창에 정수와 사칙연산이 연결된 수식을 입력하고 엔터를 친다.

수식은 숫자와 +,-,x,/ 의 네 문자만 허용된다. 마지막에는 =를 붙인다. (곱하기는 반드시 알파벳 소문자 엑스를 사용함)

![image](https://user-images.githubusercontent.com/105068708/209697826-a9581a42-d721-45fe-bae4-a28bc994f8d3.png)

괄호는 사용하지 않는다. 수식내에 공백문자는 없어야한다. 마지막은 항상 =로 종료한다.

사칙연산의 우선순위는 없다. 수식의 맨 왼쪽부터 연산을 차례대로 처리한다.

결과는 아래와 같이  먼저 입력된 수식 스트링을 그대로 출력한 후 매 연산마다 그 단계에서의 값을 출력한다.

마지막에는 최종 정답이 표시되어야 한다. 정수이므로 소수점 처리는 하지 않는다.

숫자는 음수는 넣지 않는다고 가정한다. 하지만 연산에 의해 계산 결과는 음수도 될 수 있다.

최대 수식 길이는 512 character로 제한한다. 입력 수식은 항상 이러한 조건들을 만족하는 올바른 수식이 들어온다고 가정한다. 즉, 입력의 오류처리를 할 필요는 없다.

 
![image](https://user-images.githubusercontent.com/105068708/209697919-8ea23b88-cb0c-4b6f-89ab-6e5dc3ac0215.png)



 

# 프로그래밍 환경

옆의 첨부된 RISC-V emulator를 사용한다.  rars_5f747b9.jar  

Jar파일이므로 윈도우즈환경에서 자바를 설치한 후 실행한다.

실행하려면 jar파일을 오른쪽 마우스 클릭하여 "Open with ..."을 선택한 후 자바를 선택한다.

 

오른쪽 마우스로 잘 안되는 경우는 윈도우즈 환경에서는 cmd.exe를 실행하고 jar 파일이 있는 곳으로 cd로 들어간 후

java -jar rars_5f747b9.jar

를 실행한다.

 

성공적으로 emulator를 실행하면 다음과 같은 창이 뜬다.
![image](https://user-images.githubusercontent.com/105068708/209697648-79a17669-14d0-4d19-a380-37307a0469fd.png)




 

화면의 오른편에는 register에 들어가 있는 값들이 16진수로 표시되므로 참고한다.

F3는 소스코드를 assemble하는 단축키이다.

F5는 실행하는 단축키이다. 실행결과가 하단의 창에 출력되므로 여기서 출력된 결과를 확인 할 수 있다.

F7는 한줄씩 실행하는 step 단축키이다. 디버깅 시 유용하다. 

 

레지스터는 화면 우측의 Name이라고 보이는 t0, t1, a1, a2 등을 사용한다. Name 의 옆 숫자들이 수업시간에 사용한 X12, X27 등의 레지스터 번호에 해당한다.

 

프로그래밍을 하기 위해서는 수업시간에 배운 기본 개념 이외에도 화면에 글자를 출력하거나 입력을 받는 부분을 별도로 학습하여야 한다.

다음의 링크에 이를 위한 environment call들에 대해 설명하고 있다. 위의 스크린 샷 예제는 스트링을 console에 출력하는 간단한 코드이다.

코드를 입력한 후, 파일로 저장한 후, F3, F5를 누르면 하단에 출력이 된다.

 

https://github.com/TheThirdOne/rars/wiki/Environment-Calls (외부 사이트로 연결합니다.)

 

예제 코드들은 여기에 있으니 참조한다.

 

https://github.com/TheThirdOne/rars/tree/master/examples (외부 사이트로 연결합니다.)

 
 
 
 
 # 채점기준

구현은 다음의 단계로 나누어지므로 각 단계를 완성하면 단계별 점수를 부여한다.

 

1단계: "# "를 화면에 출력하고 수식을 입력받음

2단계: 입력된 수식을 화면에 출력

3단계: 연산 하나 스트링 처리 (1+2 또는 45x2 등 한개의 연산만 수행)

4단계: 다중 연산 스트링 처리

 

완성된 단계 만큼의 점수가 주어질 것임.

단계별 배점은: 1,2,3,4단계가 각각 10, 15, 40, 35점이다.

3단계는 사칙연산을 하나씩 점검해서 각각 10점임.


 # 과제1 채점 기준(TEST CASE)

15점: Expression:이 잘 나오는가?  오타 -1점 감점.

15점: Received가 잘 나오는가? 오타 -1점 감점. 테스트케이스별로 되는 것이 있고 안되는 것이 있는 경우 비율대로 점수부여.

단일연산케이스4개 (합40점)

10점: 12345+12345=

10점: 12345-12345=

10점: 12345x12345=

10점: 12345/12345=
 
다중연산케이스3개 (합30점)

10점: 1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1=

10점: 1+2-4x32/8+0-10/2+5x12345=

10점: 2x2x2x2x2x2x2x2x2x2x2x2x2x2x2x2x2x2x2x2=

결과는 맞지만 출력이 이상하거나 문제가 있으면 절반 감점. 결과가 틀리면 해당 케이스 0점.

 

 

# 채점방식

 

asm파일을 edit창에 로드해서 곧바로 실행할 것임.

**[중요] 채점시 미리 준비한 문자열을 ctrl-v로 해서 붙여넣고 enter를 친 후 그 결과를 볼 것이므로 ctrl-v로 입력했을 때 입력이 제대로 되는지를 직접 해보고 반드시 확인 할 것. 타자로 입력해서 동작이 잘 되더라도 ctrl-v를 하면 안되는 경우가 있음.** 

!!주의!! 코드를 (F3을 눌러서) assemble할 때, 오류가 나면 0점 처리됨.  즉, 테스트를 충분히 해서 오류가 없이 assemble되게 확인한 후 제출할 것.

지각 제출 불허. 어떠한 경우에도 예외없음. 코로나 등도 불인정.

 

 

# 제출방식

 

소스코드를 텍스트형태의 .asm파일로 저장해서 LMS에 제출한다. 파일명은 학번으로 한다.

즉, 2014382930.asm 과 같이 파일명을 해서 LMS에 제출한다.

이 파일이외에 문서, 설명 등 다른 것은 제출하지 않는다. 압축해서 제출하지 않는다.

소스코드 asm 파일 이외의 다른 파일을 제출할 경우 파일당 5점 감점.

압축파일 제출시 10점 감점.

 

 
# 부정행위 관련

 

이 과제는 개인과제이므로 반드시 혼자 과제를 수행하여야 함. 타인과 어떠한 형태로든지 코드를 공유하는 것은 금지함. 인터넷 tutorial, 교재 등 학습자료만을 가지고 완성하여야 함. 다음과 같은 사항은 금지함.

* 타인의 코드를 보면서 토의를 하는 것.
* 타인의 코드를 보고 동일하게 코딩하는 것.
* 선배,후배,친구 혹은 그 외의 비수강생에게 코딩의 도움을 받는 것.
* 먼저 완료한 학생이 다른 학생에게 참고만하라고 코드를 건네주는 것.
* 그 외의 어떠한 형태로든 타인의 코드를 보거나 공유하거나 같이 공동작업을 하는 것.

과제의 내용 이해, 해결방법 모색을 위해서 토론을 하는 것은 적극 권장하지만 코드를 보는 것은 금지됨. 코드 유사성 검사 프로그램을 사용해서 전수검사를 할 것이며 발견시 준사람과 받은사람 동일하게 과목 최종학점을 F처리함
