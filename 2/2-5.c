#include <stdio.h>
#include <math.h>

int main()
{
    // printf("37970원은\n");
    // printf("만원짜리 3개\n");
    // printf("오천원짜리 1개\n");
    // printf("천원짜리 2개\n");
    // printf("백원짜리 9개\n");
    // printf("십원짜리 7개로 구성됩니다.\n");

    int x = 37970;
    printf("만원짜리 %d개\n", x / 10000);
    printf("오천원짜리 %d개\n", (x % 10000) / 5000);
    printf("천원짜리 %d개\n", ((x % 10000) % 5000) / 1000);
    printf("백원짜리 %d개\n", (((x % 10000) % 5000) % 1000) / 100);
    printf("십원짜리 %d개로 구성됩니다.\n", ((((x % 10000) % 5000) % 1000) % 100) / 10);
}
