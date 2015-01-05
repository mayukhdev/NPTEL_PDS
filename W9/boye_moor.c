#include<limits.h>
#include<string.h>
#include<stdio.h>

#define CHAR_SET_SIZE 256

/* A function to get maximum of two integers */
int maximum (int a, int b) 
{ 
    return (a > b)? a: b; 
}

/* Preprocessing function for Boyer Moore's bad character rule */
/* R[i] is the last occurrence of the character 'str[i]' in the pattern 'str'.(Refer lecture) */
void preprocess(char *str, int size, int R[CHAR_SET_SIZE])
{
    int i;
    for(i = 0; i < CHAR_SET_SIZE; i++)
    {
       R[i] = -1;
    }

    for(i = 0; i < size; i++)
    { 
       R[(int) str[i]] = i;
    }
}

/* Complete this function using Boyer Moore's bad character rule */ 
/* For pre processing use the function preprocess() defined above */
/* You also have to print the output in this function */

/* T contains text and P contains pattern */
void patternMatcher(char *T,  char *P)
{
    int n,m,i=0,j=0,k=0,count=0,temp=0;
    int R[CHAR_SET_SIZE];
    int pos[100];
    
    n = strlen(T);
    m = strlen(P);
    
    //printf("n:%d m:%d ",n,m);
    
    preprocess(P,m,R);   
        
        i=0;                //  shift = (1,i-R[T[k]])
        while(i <= n-m)
        { 
            k= m-1;
                                      
            while(k>=0 && (T[k+i]-P[k])==0) //equal letters
            {
                    k--;
            }
            
            if(k>=0 && T[k+i]-P[k]!=0)//unequal letters, compute j.
            {                
                j = R[(int)T[k]];
                
                if(j==-1)
                    i = i+1;  
                else                   
                    i = i + j;                                     
            }         
                                              
            if(k<0)
            {
                pos[temp] = i;
                temp++;
                count++;
                i = i+1;
            }  
                        
        }
     
     for(i=0;i<count;i++)
        printf("(%d)",pos[i]);
     
     if(count==0)
        printf("-1");   
               
}

int main(void)
{
    char a[100]="ABABABABAB",b[100]="AB";
    
    patternMatcher(a,b);
    
    return 0;
}
