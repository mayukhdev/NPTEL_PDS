/* You may re-write the whole code. The snippet given below is only as a guideline */

#include <stdio.h>
#include <stdlib.h>

typedef struct mat
{    
    int** matValues;
}matrixType;

matrixType initializeMatrix(matrixType anyMatrix, int numVertices)
{
	int i, j;
	
	anyMatrix.matValues = (int**) calloc(numVertices, sizeof(int*));
	for (i=0; i<numVertices; i++)
		anyMatrix.matValues[i] = (int*) calloc(numVertices, sizeof(int));
	for (i=0;i<numVertices;i++)
		for (j=0; j<numVertices;j++){
			anyMatrix.matValues[i][j] = 0;
	}
	return anyMatrix;
}

matrixType multiply(matrixType M1, matrixType M2, int numVertices){

	int i,j,k;
	matrixType resultMatrix;
        resultMatrix = initializeMatrix(resultMatrix,numVertices);
	for (i=0;i<numVertices;i++){
		for (j=0;j<numVertices;j++){
			resultMatrix.matValues[i][j] = 0;
			for (k=0;k<numVertices;k++){
				resultMatrix.matValues[i][j] = resultMatrix.matValues[i][j]+M1.matValues[i][k]*M2.matValues[k][j];
			}	
		}
	}	
	return resultMatrix;
}


int main(void)
{
    int i,j,k,n,ans=0;
    matrixType m1,m2;
    
    scanf("%d %d",&n,&k);
    
    m1 = initializeMatrix(m1,n);
        
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&m1.matValues[i][j]);
    }
    
    m2 = initializeMatrix(m1,n);
    
    m2 = m1;

    for(i=0;i<k-1;i++)
        {
            m2 = multiply(m1, m2, n);
            m1 = m2; 
        }
       
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            {
                if(i>=j)
                    m2.matValues[i][j] = 0;       
            }
    }
        
 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            ans = ans + m2.matValues[i][j];   
    }
        
    
    printf("%d",ans);
   
        
    return 0;
}











