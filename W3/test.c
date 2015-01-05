#include<stdio.h>
#include<string.h>

void printChars(char *p, char *q);
int main()
{
   char array[50];
   char *c=array;
   scanf("%s",c);
   scanf("%s",c);
   
   printChars(c+1,c+3);  
   
    printf("\n%d",strlen(c));
   
     

    return 0;
}

void printChars(char *p, char *q)
{

    if (p==NULL){
        printf("0");
    }
    else{
        while(p <= q){
            printf("%c",*p);
            p++;
        }
    }
}
