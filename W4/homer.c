#include<stdio.h>

//int P(int k,int m,int n,int *a,int i);

int main (void)
{
    int n,m,k,a[11],ans=0,i;
    
    scanf("%d %d %d",&n,&m,&k);
    
    for(i=0;i<=n;i++)
        scanf("%d",&a[i]);
    
    //ans = P(k,m,n,a,0);    
  
    for(i=0;i<=m;i++)
    {        
         ans = a[i] + k* ans;
    }    

    printf("%d",ans);
    return 0;
}

/*int P(int k,int m,int n,int *a,int i)
{
    if(i==m)
        return a[n];
    
    else
        return (a[n] + k * P(k,m,n-1,a,i+1));    
        
}*/
