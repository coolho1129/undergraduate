*****
     *
     *
     *
*****
이런거 출력하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            if (i == 0 || i == 4) {
                printf("*");
            }
            else {
                printf(" ");
                if (j == 4) {
                    printf("*");
                }
            }
        }
        printf("\n");
    }
}