#include<stdio.h>
#include<string.h>
#define MAX 100


int main(void)
{
    char inp[100][10],new[100][10];
    
    int n = 2,i;
    
    for(i=0;i<n;i++)
        scanf("%s",inp[i]);
    
    for(i=0;i<n;i++)
        printf("%s ",inp[i]);
        
    strcpy(new[0],inp[0]);
    
    i = strcmp(inp[0],new[0]);
    
    printf("%s ",new[0]);    
     printf("%d ",i);  
    
    return 0;
}


