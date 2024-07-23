#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct tree *treepointer;

typedef struct
{
	int key;
} element;

struct tree
{
	element data;
	treepointer leftchild, rightchild;

} tree;

element *search(treepointer root, int key)
{
	if (!root) // root값이 NULL값이면
		return NULL;

	if (key == (root->data).key)
		return &(root->data);

	if (key < root->data.key)
		return search(root->leftchild, key);
	return search(root->rightchild, key);
}
treepointer modifiedsearch(treepointer node, int key)
{
	if (!node) // root값이 NULL값이면
		return NULL;

	if (key == node->data.key)
		return NULL;

	if (key < (node->data).key)
	{
		if (!(node->leftchild))
		{
			return node;
		}

		else
			return modifiedsearch(node->leftchild, key);
	}

	else
	{
		if (!(node->rightchild))
		{
			return node;
		}
		else
			return modifiedsearch(node->rightchild, key);
	}
}

void insert(treepointer *node, int k)
{
	treepointer ptr, temp = modifiedsearch(*node, k);
	// printf("0");
	if (temp || !(*node))
	{
		// printf("1");
		ptr = calloc(1, sizeof(*node));
		ptr->data.key = k;
		// ptr->data.item = theitem;
		ptr->leftchild = ptr->rightchild = NULL;
		if (*node)
		{
			if (k < temp->data.key)
				temp->leftchild = ptr;
			else
				temp->rightchild = ptr;
		}
		else
			*node = ptr;
	}
}

void preorder(treepointer ptr)
{
	if (ptr)
	{
		printf("%d ", ptr->data.key);
		preorder(ptr->leftchild);
		preorder(ptr->rightchild);
	}
}

void inorder(treepointer ptr)
{
	if (ptr)
	{
		inorder(ptr->leftchild);
		printf("%d ", ptr->data.key);
		inorder(ptr->rightchild);
	}
}

void postorder(treepointer ptr)
{
	if (ptr)
	{
		postorder(ptr->leftchild);
		postorder(ptr->rightchild);
		printf("%d ", ptr->data.key);
	}
}

int main()
{
	FILE *f1 = fopen("input1.txt", "r");
	FILE *f2 = fopen("input2.txt", "r");
	int N;
	treepointer root = NULL;

	while (fscanf(f1, "%d", &N) != EOF)
	{
		insert(&root, N);
	}
	printf("Preorder: ");
	preorder(root);
	printf("\nInorder: ");
	inorder(root);
	printf("\nPostorder: ");
	postorder(root);

	printf("\nSearch: ");
	while (fscanf(f2, "%d", &N) != EOF)
	{
		if (search(root, N) != NULL)
			printf("1 ");
		else
			printf("0 ");
	}
}
