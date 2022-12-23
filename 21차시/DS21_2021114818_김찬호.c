#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define False 0
#define True 1
typedef int boolean;

int hashFunction(int key,int tableSize) {
	return key % tableSize;
}

void hashInsert(int* table, int* input, int tableSize ,int inputSize) {
	int key = 0;
	for (int i = 0; i < inputSize; i++) {
		key = hashFunction(input[i],tableSize);
		
		while(table[key]) {
			key=hashFunction(key+1,tableSize);
		}
		
		table[key] = input[i];
		//printf("%d ", input[i]);
	}
	
}

void hashSearch(int* table, int *find,int tableSize, int findSize) {
	int key=0;
	boolean isfind = False;
	printf("Search : \n");
	for (int i = 0; i < findSize; i++) {
		key = hashFunction(find[i],tableSize);
		while (table[key]) {
			if (table[key] == find[i]) {
				printf("S");
				isfind = True;
				break;
			}
			else
				key = hashFunction(key + 1,tableSize);

		}
		if (!isfind)
			printf("F");

	}
}

void printHash(int *table,int tableSize) {
	printf("Hash Table:\n");
	for (int i = 0;i<tableSize ;i++) {
		printf("%d: ", i);
		if (table[i] != 0)
			printf("%d", table[i]);
		puts("");
	}
}

void main() {
	
	FILE* f = fopen("input.txt", "r");
	int D,N, M,*hashtable,*input,*find;
	fscanf(f, "%d %d %d", &D, &N, &M);
	hashtable = calloc(D, sizeof(int));
	input = calloc(N, sizeof(int));
	find = calloc(M, sizeof(int));

	for (int i = 0; i < N; i++)
		fscanf(f,"%d", &input[i]);
	for (int i = 0; i < M; i++)
		fscanf(f,"%d", &find[i]);
	
	hashInsert(hashtable, input,D,N);
	printHash(hashtable, D);
	hashSearch(hashtable, find, D, M);

	free(hashtable);
	free(input);
	free(find);
	fclose(f);
}