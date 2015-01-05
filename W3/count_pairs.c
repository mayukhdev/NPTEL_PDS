#include<stdio.h>

//find the number of pairs (A[i], A[j]) such that i < j and A[i]^A[j] > A[j]^A[i].

int power(int x, int y);

int main(void)
{
    int n,i,j,pair=0;
    scanf("%d",&n);
    
    #define MAX n
    
    int A[MAX];
    
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(power(A[i],A[j]) > power(A[j],A[i]))
                ++pair;   
        }
    }
    
    printf("%d",pair);

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
