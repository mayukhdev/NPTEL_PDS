#include<stdio.h>
#define MAX 20

/*  Write a program that takes two input strings S1 and S2 and finds if S2 is a substring of S1 or not. 
If S2 is a substring of S1, the program should print the index at S1 at which there is a match. 
If S2 is not a substring of S1, the program should print -1. 
If S2 appears in S1 multiple times, print the first index in S1 at which the match occurred.    */

int main(void)
{
    int i,j,index,m,count=0;
    char s1[MAX]="hellow" ,s2[MAX]="hello";
    
    //scanf("%s %s",s1,s2);
    
    i=j=m=0;
    
    while(s2[m]!='\0')
    {
        ++count;
        m++;   
    }
    
    while(s1[i]!='\0')
    {
        if(s1[i]==s2[j])
        {
            index= i;
            for(i=i+1,j=j+1;s2[j]!='\0' && s1[i]==s2[j];++i,++j)
            ;
            
            if((i+1-index)== count)
            {
                printf("%d",index);
                return 0;
            }    
               
        }
        
        i++;   
    }
    
    printf("-1");
    
    return 0;
}
