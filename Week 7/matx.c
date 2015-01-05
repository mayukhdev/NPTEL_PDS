#include<stdio.h>
#include<limits.h>
#include<stdlib.h> 

int MatrixChainOrder(int p[],int n);
 
int main()
{
	int n,i;
	scanf("%d",&n);
	int *p = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
 	printf("%d",MatrixChainOrder(p, n));
    return 0;
}

int MatrixChainOrder(int p[], int n)//1,2,3,4,5
{
    int **m;
    int i,j,l,k,q=0;
    
    
    m = (int**)malloc((n-2) * sizeof(int*));
    for(i=0;i<n-1;i++)
        m[i] = (int*)malloc((n-2) * sizeof(int));
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1;j++)
            m[i][j]=0; 
    
    /*s = (int**)malloc((n-1) * sizeof(int*));
    for(i=0;i<n-1;i++)
        s[i] = (int*)malloc((n-1) * sizeof(int));
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1;j++)
            s[i][j]=0;
    */
    
    for(l=1;l<n-1;l++)
        {
            for(i=0;i<n-l-1;i++)
            {  
                j=i+l;
                for(k=i;k<j;k++)
                {
                    q= m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                    if(m[i][j]==0 || q<m[i][j])
                        m[i][j]=q;
                }       
            }
        }
        
     for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++)
        {
            printf("%d ",m[i][j]);   
        }
        printf("\n");
      }     
            
     return m[0][n-2];               
        
}








