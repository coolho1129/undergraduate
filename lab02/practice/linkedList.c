#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudentNode {
  	
	char name[100];
  	int id;
  	float gpa;
  	struct StudentNode * next;
};

struct StudentNode * createNode (char name[], int id, float gpa){
  	
	struct StudentNode *ptr;
  	ptr = (struct StudentNode*) malloc (sizeof(struct StudentNode));
  	ptr->id = id;
  	ptr->gpa = gpa;
  	strcpy (ptr->name, name);
  	ptr->next = NULL;

  	return ptr;
}

void printData (struct StudentNode * first){
  
	while (first != NULL) {
    		printf ("%s %d %.2f \n", first->name, first->id, first->gpa);
    		first = first->next;
  	}
}	

void insertData (struct StudentNode** first, char name[], int id, float gpa){
  	
	struct StudentNode *tmp;
  	tmp = createNode (name, id, gpa);
	tmp->next = *first;
  	*first = tmp;

  	printData (*first);
}
int main () {
  
	struct StudentNode *top;
  	struct StudentNode *tmp;

  	top = createNode ("Kim", 10, 3.5);
  	tmp = createNode ("Lee", 20, 3.6);

  	top->next = tmp;

  	insertData (&top, "Park", 30, 4.0);
  	printf ("After insertion \n");
  	printData (top);
}
