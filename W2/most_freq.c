#include<stdio.h>
#define MAX 10000

//Write a program to read a sequence of N integers and print the number that appears the maximum number of times in the sequence

int main(void)
{
    int i,j,n,max,ans,count,num;//num
    int test[MAX],list[MAX];
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        list[i]=0;
        
    for(i=0;i<n;i++)
        test[i]=0;    
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        list[i]=num;                    
    }
    
    
    max = count = ans= 0;
    
    for(i=0;i<n;i++)
    {
        
        test[i] = list[i];
        
        if(i!=0)
            {        
                if(test[i]==ans)
                    continue;
            } 
            
        for(j=0;j<n;j++)
            {
                if(list[j]==test[i])
                    ++count;
            }
            
        if(i==0)
         {
            max = count;
            ans = test[i];
            
         }   
        else
            {
                if(max<count)
                {
                    max = count;
                    ans = test[i];
                    
                }
            }
            
            count = 0;
           
    }
    
    printf("%d",ans);
    
    return 0;
}
