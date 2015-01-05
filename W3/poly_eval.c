#include<stdio.h>

int power(int x, int y);

int main()
{
    int n,x,i,answer=0,current;
    scanf("%d %d",&n,&x);
    
    #define MAX n
    
    int arr[MAX+1];
    
    for(i=0;i<=n;i++)
        arr[i]=0;
    for(i=0;i<=n;i++)
        scanf("%d",&arr[i]);
    
    current = n;
        
    for(i=0;i<=n;i++)   
        answer= answer + (arr[i]* power(x,current--));
              
    printf("%d",answer);
    
    return 0;
}

/* THE CODE BELOW WILL BE AUTOMATICALLY UNCOMMENTED DURING EXECUTION. PLEASE DO NOT MODIFY ANYTHING BELOW THIS LINE.*/ 

 int power(int x, int y)
 {
   int result = x;

   if(y == 0) return 1;
   if(x < 0 || y < 0) return 0;

   for(int i = 1; i < y; ++i)
   result *= x;

   return result;
}
