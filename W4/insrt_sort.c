#include<stdio.h>

int main(void)
{
    int a[]= {10,2,4,8,9,1,4,0,231},i,j,key;
    
    int n = sizeof(a)/sizeof(int);
    
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
         
    
    for(j=1;j<n;j++)
    {
        key = a[j];
        i = j-1;
        
        while(i>=0 && a[i] > key)
        {

            a[i+1] = a[i];
            i = i-1;
           printf("\n");           
        } 
        
        a[i+1] = key;  
    }
    
    printf("\n");
    
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    
    printf("\n");    
        
    return 0;
}
