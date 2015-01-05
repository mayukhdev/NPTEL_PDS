#include<stdio.h>

int pwr(int,int);

int main(void)
{
    int sq,n,p;
    scanf("%d %d",&n,&p);
    
    sq = pwr(n,p);
    printf("%d\n",sq);
    
    return 0;
}

int pwr(int n,int p)
{
    printf("n=%d p=%d\n",n,p);
    if(p==0)
        return 1;
    if(p==1)
        return n;
    if(p%2!=0)
        return pwr(n*n,(p-1)/2) * n;
    else
        return pwr(n*n,p/2);            
}
