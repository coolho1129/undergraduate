#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
typedef struct CalculatorNode {
	int a;
	int b;
	char name[20];
	int (*fptr) (int, int);
	struct CalculatorNode* next;

}CalculatorNode;

CalculatorNode* createNode(int a, int b, char op[], int* fptr);
CalculatorNode* insertData(CalculatorNode* h, int a, int b, char op[], int* fptr);
void printList(CalculatorNode* h);
void printResult(CalculatorNode* h);
CalculatorNode* delete_all(CalculatorNode* h);
int add(int a, int b);
int sub(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);


int main() {
	int menu;
	int a, b;
	char op[20] = { 0 };
	int* fptr = NULL;
	CalculatorNode* h = NULL;
	for (;;) {
		printf("======================================================\n");
		printf("1:입력 2:입력 값 확인 3:결과 출력 4:전체 삭제 5:종료\n");
		printf("메뉴를 입력하세요: ");
		scanf("%d", &menu);
		printf("======================================================\n");
		int i = 1;
		if (menu == 1) {
			while (i) {
				printf("======================================================\n");
				printf("정수1 정수2 연산 순으로 입력해주세요\n");
				printf("연산 종류: add, sub, multiply, divide\n");
				printf("Ex) 1 2 add\n");
				scanf("%d %d %s", &a, &b, op);
				printf("======================================================\n");

				if (strcmp("divide", op) == 0) {
					if (!b) {
						printf("나누는 값이 0입니다.다시 입력하세요.\n");
						continue;
					}
					fptr = divide;

				}

				else if (strcmp("add", op) == 0) {
					fptr = add;
				}
				else if (strcmp("sub", op) == 0) {
					fptr = sub;
				}
				else if (strcmp("multiply", op) == 0) {
					fptr = multiply;
				}
				i--;

			}
			h = insertData(h, a, b, op, fptr);
		}
		else if (menu == 2) {
			printList(h);

		}
		else if (menu == 3) {
			printResult(h);

		}
		else if (menu == 4) {
			h = delete_all(h);
		}

		else if (menu == 5) {
			printf("프로그램을 종료합니다!\n");
			break;
		}
	}
	return 0;
}

CalculatorNode* createNode(int a, int b, char op[], int* fptr) {
	CalculatorNode* ptr = calloc(1, sizeof(CalculatorNode));
	ptr->a = a;
	ptr->b = b;
	strcpy(ptr->name, op);
	ptr->fptr = fptr;
	ptr->next = NULL;

	return ptr;
}

CalculatorNode* insertData(CalculatorNode* h, int a, int b, char op[], int* fptr) {
	CalculatorNode* p, * curr;
	curr = createNode(a, b, op, fptr);

	if (!h) {
		h = curr;
	}
	else {
		for (p = h; p->next; p = p->next);
		p->next = curr;
	}

	return h;
}

void printList(CalculatorNode* h) {
	CalculatorNode* p = h;
	printf("======================================================\n");
	printf("입력 값\n");
	for (; p; p = p->next) {
		printf("%d %d %s\n", p->a, p->b, p->name);
	}
	printf("======================================================\n");
}

void printResult(CalculatorNode* h) {
	CalculatorNode* p = h;
	printf("======================================================\n");
	printf("결과 값\n");
	for (; p; p = p->next) {
		printf("%d %d %s %d\n", p->a, p->b, p->name, p->fptr(p->a, p->b));
	}
	printf("======================================================\n");
}


CalculatorNode* delete_all(CalculatorNode* h) {
	printf("======================================================\n");
	printf("전체 삭제 완료\n");
	printf("======================================================\n");
	CalculatorNode* delnode = h;
	if (!h)
		return NULL;

	while (h->next != NULL) {
		delnode = h;
		h = h->next;
		free(delnode);


	}
	return NULL;


}

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;
}
