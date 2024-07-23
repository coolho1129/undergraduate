#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 연결리스트 구조체 선언
typedef struct linked_list {

	int data;
	struct linked_list* next;
}NODE;

// 앞에 계속 넣기
NODE* insertHead(NODE* h, int data) {

	NODE* node;

	node = (NODE*)malloc(sizeof(NODE));

	node->data = data;

	node->next = h;
	h = node;

	return h;
}

//연결리스트에 값이 존재하는지 확인하는 함수
void search_num(NODE* h, int search)
{
	NODE* p;
	p = h;
	while (p != NULL)
	{
		if (p->data == search)
		{
			printf("true");
			break;
		}
		p = p->next;
	}
	if (p == NULL)
		printf("false");
}

//연결리스트 출력함수
void printList(NODE* h) {

	NODE* p = h;

	while (p != NULL) {

		printf("%d ", p->data);
		p = p->next;

	}
	printf("\n");
}

//연결리스트 정렬입력
NODE * insertSorted(NODE* h, int data)
{
	NODE* node, * p, * q;

	node = (NODE*)malloc(sizeof(NODE));
	node->data = data;
	p = h, q = h;
	while (p != NULL)
	{
		if (p->data > data)
			break;

		q = p;
		p = p->next;
	}
	if (p == h) {
		node->next = h;
		h = node;
	}
	else {
		node->next = p;
		q->next = node;

	}
	return h;
}

//연결리스트 정렬입력+중복제거
NODE* insertNoDuplicate(NODE* h, int data)
{
	NODE* node, * p, * q;

	node = (NODE*)malloc(sizeof(NODE));
	node->data = data;

	p = h, q = h;
	while (p != NULL)
	{
		if (p->data > data)
			break;

		if (p->data == data)
			return h;
		q = p;
		p = p->next;
	}

	if (p == h) {
		node->next = h;
		h = node;
	}
	else {
		node->next = p;
		q->next = node;

	}
	return h;



}
//노드제거
NODE* deleteNode(NODE* h, int data)
{
	NODE* p, * q;
	p = h, q = h;
	while (p != NULL)
	{
		if (p->data == data) {
			break;
		}
		if (p->data > data)
			return h;
		q = p;
		p = p->next;

	}
	if (p == NULL)
		return h;
	
	else if (p == h) {
		h = h->next;
		free(p);
		return h;
	}
	else {
		q->next = p->next;
		free(p);
		return h;

	}

}

//뒤로 추가하기
NODE* append(NODE* h, int data) {

	NODE* p, * curr;

	curr = (NODE*)calloc(1, sizeof(NODE));
	curr->next = NULL;
	curr->data = data;

	if (h == NULL)
		h = curr;

	else {

		p = h;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = curr;

	}
	return h;
}

//리스트 값 증가시키기
void increaseList(NODE* h)
{
	NODE* p;
	p = h;
	while (p != NULL)
	{
		p->data += 10;
		p = p->next;
	}
}

//최솟값 구하기
int findMIN(NODE* head)
{
	NODE* p;
	p = head;
	int min = p->data;

	while (p != NULL)
	{
		if (min > p->data)
			min = p->data;
		p = p->next;
	}
	return min;
}
// 최대값 구하기
int findMAX(NODE* head)
{
	NODE* p;
	p = head;
	int max = p->data;

	while (p != NULL)
	{
		if (max < p->data)
			max = p->data;
		p = p->next;
	}
	return max;

}
// 합 구하기
int sumList(NODE* head)
{
	int sum = 0;
	NODE* p;
	p = head;
	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

//두 연결리스트를 합치는 함수
NODE* appendList(NODE* h1, NODE* h2)
{
	NODE* p1, * p2;
	p1 = h1;
	p2 = h2;
	while (p1->next != NULL)
	{
		p1 = p1->next;
	}
	p1->next = p2;


	return h1;



}