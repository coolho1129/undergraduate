#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct {
   int accNum;
   char name[30];
   double balance;
} account;

void main()
{
   account act[100] = { 0 };
   char search[30];
   int menu, i = 0, j, cnt = 0;
   double input, output, sum = 0;
   FILE* fp = fopen("bank.bin","rb+");
   if (!fp) {
      fp = fopen("bank.bin", "wb+");
   }
   while (!feof(fp)) {
      fread(&act[cnt], 1, sizeof(account), fp);
      cnt++;
   }
   cnt--;
   while (1)
   {
      scanf("%d", &menu);
      if (menu == 1)
      {
         for (i = 0;; i++)
         {
            scanf("%d", &act[cnt].accNum);
            if (act[cnt].accNum == -1)
            {
               break;
            }
            scanf("%s %lf", act[cnt].name, &act[cnt].balance);
            cnt++;
         }
      }
      else if (menu == 2)
      {
         scanf("%s", search);
         for (j = 0; j < cnt; j++)
         {
            if (strcmp(act[j].name, search) == 0)
            {
               printf("%d %s %.2lf\n", act[j].accNum, act[j].name, act[j].balance);
            }
         }
      }
      else if (menu == 3)
      {
         scanf("%s %lf", search, &input);
         for (j = 0; j < cnt; j++)
         {
            if (strcmp(act[j].name, search) == 0)
            {
               act[j].balance += input;
               printf("%d %s %.2lf\n", act[j].accNum, act[j].name, act[j].balance);
            }
         }
      }
      else if (menu == 4)
      {
         scanf("%s %lf", search, &output);
         for (j = 0; j < cnt; j++)
         {
            if (strcmp(act[j].name, search) == 0)
            {
               act[j].balance -= output;
               printf("%d %s %.2lf\n", act[j].accNum, act[j].name, act[j].balance);
            }
         }

      }
      else if (menu == 5)
      {
         sum = 0;
         for (j = 0; j < cnt; j++)
         {
            sum += act[j].balance;
         }
         printf("Total=%.2lf\n", sum);
         for (j = 0; j < cnt; j++)
         {
            printf("%d %s %.2lf\n", act[j].accNum, act[j].name, act[j].balance);
         }
      }
      else if (menu == 6)
      {
         break;
      }
   }
   fseek(fp, 0, SEEK_SET);
   for (j = 0; j < cnt; j++)
      fwrite(&act[j], sizeof(account), 1, fp);
   fclose(fp);

}