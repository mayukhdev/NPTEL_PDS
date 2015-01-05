#include<stdio.h>

int main (void)
{
    unsigned int n;
    int a,dig;
    a=0;
    
    scanf("%i",&n);
    
   while(n/10>0)
   {
        while(n!=0)
        {
        dig = n % 10;
        a = a + dig;
        n = n/10;
        }
        
        n = a;  
        a= 0;     
   }
   
    printf("%d",n);    
 
 return 0;   
}    
