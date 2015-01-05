#include <iostream>
#include <cstring>

using namespace std;

struct matrixType
{
    int matDimension;
    int matValues[10][10];
};

class MatrixADT
{

    private:
        matrixType resultMatrix;

    public:

       //Member function declarations
  
        void intializeResultMatrix(int);
        matrixType add(matrixType, matrixType);
        matrixType subtract(matrixType,matrixType);
        matrixType multiply(matrixType,matrixType);
        void printResult();
};

//Member functions of Matrix class to be defined here
matrixType MatrixADT::add(matrixType M1, matrixType M2)
{
    int i,j;
        
    for(i=0;i<resultMatrix.matDimension;i++)
    {
        for(j=0;j<resultMatrix.matDimension;j++)
        {
            resultMatrix.matValues[i][j] = M1.matValues[i][j] + M2.matValues[i][j];
        }
    }
    
    return resultMatrix;
}

matrixType MatrixADT::subtract(matrixType M1, matrixType M2)
{
    int i,j;
        
    for(i=0;i<resultMatrix.matDimension;i++)
    {
        for(j=0;j<resultMatrix.matDimension;j++)
        {
            resultMatrix.matValues[i][j] = M1.matValues[i][j] - M2.matValues[i][j];
        }
    }
    
    return resultMatrix;

}

matrixType MatrixADT::multiply(matrixType M1, matrixType M2)
{

    int i,j,k;
        
    for(i=0;i<resultMatrix.matDimension;i++)
    {
        for(j=0;j<resultMatrix.matDimension;j++)
        {
            for(k=0;k<resultMatrix.matDimension;k++)
                resultMatrix.matValues[i][j] += M1.matValues[i][k] * M2.matValues[k][j];
        }
    }
    
    return resultMatrix;

}

void MatrixADT::intializeResultMatrix(int dim)
{
    int i,j;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
                resultMatrix.matValues[i][j]=0;
    }
    resultMatrix.matDimension = dim;        
}

int main()
{

    MatrixADT maX;
    matrixType M1, M2, M3;
    char op;
    int dim,i,j;
    
    cin>>dim>>op;
    
    /*for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
                M1.matValues[i][j]=0;
    }
    
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
                M2.matValues[i][j]=0;
    }*/
    
    for(i=0;i<dim;i++)
    {
        M1.matDimension = dim;
        for(j=0;j<dim;j++)
                cin>>M1.matValues[i][j];    
            
    }
    
    for(i=0;i<dim;i++)
    {
        M2.matDimension = dim;
        for(j=0;j<dim;j++)           
                cin>>M2.matValues[i][j];    
            
    }
    
    switch(op)
    {
        case '+':   
                    maX.intializeResultMatrix(dim);
                    M3 = maX.add(M1,M2);
                    break;
        
        case '-':
                    maX.intializeResultMatrix(dim);   
                    M3 = maX.subtract(M1,M2);
                    break;
        
        case '*':
                    maX.intializeResultMatrix(dim);
                    M3 = maX.multiply(M1,M2);
                    break;
    }
/*Enter your code here to accept two input matrices as instances of class Matrix and perform the operations using member functions, display the result matrix using member function*/

/* DO NOT EDIT the code below; if you edit it, your program will not give correct output */
    
maX.printResult();
            
}


void MatrixADT::printResult(){

    int i,j;
    for (i=0;i<resultMatrix.matDimension;i++){
        for (j=0; j<resultMatrix.matDimension-1;j++){
            cout<<resultMatrix.matValues[i][j]<<" ";
        }
       cout <<resultMatrix.matValues[i][j]<<"\n";
    }
    cout <<"Done";
}

