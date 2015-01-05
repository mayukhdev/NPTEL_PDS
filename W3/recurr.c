#include<stdio.h>

int T(int);

int main(void)
{
    int n;
    
    scanf("%d",&n);
    
    int k = T(n);
    
    printf("%d",k);
    
    return 0;
}

int T (int n)
{
    if(n==0)
        return 1;
    else
        return T(n-1)+2*n;    
}
