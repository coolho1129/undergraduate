#define _CRT_SECURE_NO_WARNINGS 
#define False 0
#define True 1
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include <math.h>


typedef struct linked_list {

    int expon;
    int coef;
    struct linked_list* next;

}Node;


Node* append(Node *h,int coef,int expon) {

    Node* poly, * p;
   
    poly=(Node*)calloc(1, sizeof(Node));
    poly->next = NULL;
    poly->coef=coef;
    poly->expon=expon;
    

    if (h == NULL) {
        h = poly;
    
    }
    else {
        p = h;

        while(p->next!=NULL){

            p = p->next;


        }
        p->next = poly;
    
    
    }

    return h;
}




Node* padd(Node* h1, Node* h2, Node *h3) {

    Node* p1=h1, * p2=h2, * p3=h3;
    int coef, expon;
   
    while (p1!=NULL&&p2!=NULL) {
        
        if ((p1->expon) > (p2->expon)) {
            if (p1->expon == 0)  
                p3 = append(p3, p1->coef, p1->expon);
           // printf("%d %d %p\n", p3->coef, p3->expon, p3->next);
            p1 = p1->next;
            
        }

        else if ((p1->expon) == (p2->expon)) {
           
           
            coef = p1->coef + p2->coef;
            expon = p2->expon;
            //if (coef != 0)
            p3 = append(p3, coef, expon);
            //printf("%d %d %p\n", p3->coef, p3->expon, p3->next);
            p1 = p1->next;
            p2 = p2->next;
          
        }

        else {
            p3 = append(p3, p2->coef, p2->expon);
           // printf("%d %d %p\n", p3->coef, p3->expon, p3->next);
            p2 = p2->next;
           
        }

    }
    for(;p1;p1=p1->next)
        p3 = append(p3, p1->coef, p1->expon);
    for (; p2; p2=p2->next)
        p3 = append(p3, p2->coef, p2->expon);

    return p3;

}

void print_poly(Node* h) {


    Node* p = h;
  
   if(p->coef!=0)
    printf("%dx^%d", p->coef, p->expon);
  else
      printf("%d", p->coef);
    
    
    p = p->next;
    while (p!= NULL) {
        
        if (p->coef > 0) {
            if(p->expon==0)
                printf("+%d", p->coef);
            
            else
                printf("+%dx^%d", p->coef, p->expon);
        }


        else if (p->coef < 0) {

            if (p->expon == 0)
                printf("-%d", abs(p->coef));

            else
                printf("-%dx^%d", abs(p->coef), p->expon);

        }
        
        
        
        p = p->next;
    }
    
}

int main(void) {
    
    FILE* f1,*f2;
    Node *poly1=0, *poly2=0,*poly3=0,*result=0;
    int coef, expon,N;
    f1 = fopen("a.txt", "r");
    f2 = fopen("b.txt", "r");
    
    fscanf(f1, "%d", &N);
    for(int i=0;i<N;i++){
        fscanf(f1, "%d %d", &coef,&expon);
        poly1 = append(poly1, coef, expon);
    
    
    }
   
    fscanf(f2, "%d", &N);
    for (int i = 0; i < N; i++) {
        fscanf(f2, "%d %d", &coef, &expon);
        poly2 = append(poly2, coef, expon);


    }
    //print_poly(poly1);
   // printf("\n");
   // print_poly(poly2);
    //  printf("\n");
    
    result = padd(poly1, poly2, poly3);
    
    print_poly(result);

    free(poly1);
    free(poly2);
    free(result);
    fclose(f1);
    fclose(f2);
	
  
}