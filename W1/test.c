#include<stdio.h>
#define MAX 10000

int main(void)
{
    scanf("%d %d",&m,&n);
    #define M m
    #define N n
    
    int arr[M][N];
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",arr[i][j]);
    }
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",arr[i][j]);
        printf("\n");    
    }
     
}
