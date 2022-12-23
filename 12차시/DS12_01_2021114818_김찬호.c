#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include <math.h>
#define maxsize 1000

typedef struct treenode* treepointer;
typedef int element;

typedef struct treenode {
	
	element data;
	treepointer leftchild, rightchild;

}treenode;

tree[maxsize];

void init_tree(treepointer *rootnode) {
	(*rootnode)= calloc(1, sizeof(treenode));

}

void  maketree(treepointer *t, int index ,element data[]) {
	
	treepointer leftnode, rightnode;
	(*t)->data = data[index];
	
	if (data[2*index]==-1|| data[2 * index] == 0) {
		
		(*t)->leftchild = NULL;
			
	}
	else {
		leftnode = calloc(1, sizeof(treenode));
		(*t)->leftchild = leftnode;
		maketree(&leftnode, 2 * index, data);
	}


	if (data[2 * index+1] == -1 || data[2 * index+1] == 0) {

		(*t)->rightchild = NULL;

	}

	else {
	
		rightnode = calloc(1, sizeof(treenode));
		(*t)->rightchild = rightnode;
		maketree(&rightnode, 2 * index+1, data);
	}
}



void levelorder(int N) {
	for (int i = 0; i < N; i++) {
		if ((tree[i] != -1)&& (tree[i] != 0))
			printf("%d ",tree[i]);

	}
	printf("\n");
}

void preorder(treepointer t) {
	if (t != NULL) {
		printf("%d ",t->data);
		preorder(t->leftchild);
		preorder(t->rightchild);
	}
	

}

void inorder(treepointer t) {
	if (t != NULL) {
		inorder(t->leftchild);
		printf("%d ", t->data);
		inorder(t->rightchild);
	}
	
}

void postorder(treepointer t) {
	if (t != NULL) {
		postorder(t->leftchild);
		postorder(t->rightchild);
		printf("%d ", t->data);
	}
	
}



void main() {
	FILE* f = fopen("input.txt", "r");
	int cnt = 1;
	treepointer root = NULL;
	element input;
	init_tree(&root);
	while (fscanf(f, "%d", &input) != EOF) {

		tree[cnt++] = input;

	}
	maketree(&root, 1, tree);

	printf("Level Order: ");
	levelorder(cnt);
	
	printf("Preorder: ");
	preorder(root);
	printf("\n");

	printf("Inorder: ");
	inorder(root);
	printf("\n");
	
	printf("Postorder: ");
	postorder(root);
	printf("\n");

	free(root);
	fclose(f);

}