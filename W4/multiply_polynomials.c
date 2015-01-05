#include<stdio.h>

/*A polynomial of degree n is of the form P(x) = a(nxn) + a(n-1)x(n-1) + … + a0. 
Given two polynomials f(x) and g(x) of degrees n and m respectively, write a program to find the polynomial h(x), multiply.*/

int main (void)
{
    int m,n,i,a[101],b[101],c[202],j;
    
    scanf("%d %d",&n,&m);
    
    for(i=n;i>=0;i--)
        scanf("%d",&a[i]);       
    
    for(i=m;i>=0;i--)
        scanf("%d",&b[i]);
        
    printf("%d\n",m+n);
    
    for(i=0;i<=m+n;i++)
            c[i] = 0;
    
    for(i=n;i>=0;i--)
    {
        for(j=m;j>=0;j--)
            c[i+j] = c[i+j] + a[i]*b[j];       
    }    

    for(i=0,j=m+n;i<=j;i++,j--)
       {
           int temp=0;
           temp = c[i];
           c[i] = c[j];
           c[j]= temp;
       }
    
    for(i=0;i<=m+n;i++)
            {
                if(i==0)
                    printf("%d",c[i]);   
                else
                    printf(" %d",c[i]);
            }         
    return 0;
}
