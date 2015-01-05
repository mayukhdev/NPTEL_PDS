#include<stdio.h>
#include<string.h>

void printChars(char *p,char *q);//function prototype

int main(void)

{
    int n,i,j;
    char s[100],*sptr,*p,*q;
    
    scanf("%s",s);
    sptr = s;
    
    n = strlen(sptr);
    
    p = sptr + 0;
    
    i=0;
    j=n-1;
    
    if(sptr[i]!=sptr[j])
                p=NULL;
 
    for(i=0,j=n-1;sptr[i]==sptr[j] && i<n && j>=0;i++,j--)
               q = sptr+i;        
        
        
    printChars(p,q);
    return 0;
}


void printChars(char *p, char *q)
{

    if (p==NULL){
        printf("0");
    }
    else{
        while(p <= q){
            printf("%c",*p);
            p++;
        }
    }
}

