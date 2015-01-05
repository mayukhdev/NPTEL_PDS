#include<stdio.h>

int power(int,int);

int main(void)
{
    int m = 3,n=13;
    
    int p = power(m,n);
    printf("%d\n",p);
    
    return 0;
}

int power(int base,int n)
{
    int p;
    if(n==1)
        return base;
    p = power(base,n/2);
    if(n%2==1)
        return p*p*base;
    else
        return p*p;    
}
