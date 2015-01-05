#include<stdio.h>

int main(void)
{
    int i,n;
    
    i=0;    
    do
    {
        scanf("%d",&n);
        i = i+n;
    }while(n!=-1);
    

    printf("%d",i+1);    
        
}
