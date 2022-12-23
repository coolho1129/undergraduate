#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000


void printArray(int n);
int array[MAXSIZE][2];



void swap(int x, int y) {
	for (int i = 0; i < 2; i++) {
		int temp = array[x][i];
		array[x][i] = array[y][i];
		array[y][i] = temp;
	}
}


void QuickSort(int left, int right,int key) {

	int pivot, i, j;


	if (left < right) {
		i = left;
		j = right + 1;
		pivot = array[left][key];
		do {

			do i++; while (array[i][key] < pivot);
			do j--; while (array[j][key] > pivot);
			if (i < j)
				swap(i, j);
		} while (i < j);
		swap(left, j);
		QuickSort(left, j - 1,key);
		QuickSort(j + 1, right,key);
	}
	else
		return;





}

void printArray(int n) {
	for (int i = 0; i < n; i++) {
		for(int j=0;j<2;j++)
			printf("%5d ", array[i][j]);
		puts("");

	}
	puts("");

}


void main() {

	FILE* f = fopen("input.txt", "r");
	int n=0;
	fscanf(f,"%d", &n);
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++)
			fscanf(f,"%d", &array[i][j]);
	}

	

	//printArray(n);
	QuickSort(0, n-1,0);
	printf("Key: K1\n");
	printArray(n);
	printf("Key: K2\n");
	QuickSort( 0, n-1 , 1);
	printArray(n);



}