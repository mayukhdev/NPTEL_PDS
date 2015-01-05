#include<stdio.h>
#include<string.h>

#define MAX 10

/*You are given two words (not necessarily meaningful words) over the lower case English alphabet.
They are to be merged into a single new word in which all the letters (including repetitions) in the given two words occur in 
increasing order (‘a’ is the least and ‘z’ is the largest) from left to right. */

void sort(char *f,int p,int r);
void merge(char *f,int p,int q,int r);

int main(void)
{
    char first[MAX+MAX],second[MAX];
    scanf("%s %s",first,second);
    int n;    
    char *f = first;
    char *s = second;
    
    strcat(f,s);
    n = strlen(f);
    
   
    sort(f,0,n-1);
    
    printf("%s",f);   
    
    return 0;
}

void sort(char *f,int p,int r)
{
    int q;
    if(p<r)
    {
        q= (p+r)/2;
        sort(f,p,q);
        sort(f,q+1,r);
        merge(f,p,q,r);
    }   
}

void merge(char *f,int i,int mid,int j)
{
    char new[MAX];
    int start,k,l;
   
   start = i;
   k = mid+1;
   l= i;
   
   while(i<=mid && k<=j)
   {
        if((f[i]-f[k])<=0)
            new[l++]= f[i++];
        else
            new[l++] = f[k++];    
   }
   
   if(i>mid)
     { 
       for(;k<=j;) 
        new[l++]=f[k++];
     }   
   else
        {
        if(k>j)
            {
            for(;i<=mid;) 
                new[l++] = f[i++];
            }      
        }
        
    for(l=start ; l<=j ; l++)
        f[l] = new[l];    
        
}
