#include<stdio.h>
/*Write a program that reads an NxN square matrix M that calculates the sum of the elements in individual rows, 
    individual columns and the two main diagonals. Among these sums, print the largest.*/

int main(void)
{
    int m,i,j,sum=0,dia1,dia2;
    int max_row,max_col,max_dia;
    scanf("%d",&m);
    
    if(m>100)
        return 1;
    
    #define M m
    
    int arr[M][M];
    
    for(i=0;i<m;i++){
        for(j=0;j<m;j++)
            scanf("%d",&arr[i][j]);
    }
    
    int sum_row[M];
    int sum_col[M];
    
    //sum of rows and store in sum_row
    for(i=0;i<m;i++)
    {
        sum=0;
        for(j=0;j<m;j++)
        {
            sum= sum + arr[i][j];
        }
        sum_row[i]= sum;
           
    }
    
    //sum of col and store in sum_col
    for(i=0;i<m;i++)
    {
        sum=0;
        for(j=0;j<m;j++)
        {
            sum= sum + arr[j][i];
        }
        sum_col[i]= sum;           
    }
    
    //sum of diagonals [0,0]
    sum=0;
    for(i=0;i<m;i++)
    {
        sum = sum + arr[i][i];
    }
    dia1=sum;
    
    //sum of diagonal [0,m-1]
    sum=0;
    for(i=m-1,j=0;i>=0;i--,j++)
    {
        sum = sum + arr[j][i];
    }
    dia2=sum;
    
    //max row
    for(i=0;i<m;i++)
    {
        if(i==0)
            max_row = sum_row[i];
        else
            {
                if(max_row<sum_row[i])
                    max_row = sum_row[i];
            }     
    }
    
    //max col
    for(i=0;i<m;i++)
    {
        if(i==0)
            max_col = sum_col[i];
        else
            {
                if(max_col<sum_col[i])
                    max_col = sum_col[i];
            }     
    }
    
    //max dia
    if(dia1>dia2)
        max_dia=dia1;
    else
        max_dia=dia2; 
        
    //compare the 3
    if(max_row>max_col)
    {
        if(max_row>max_dia)
           printf("%d",max_row);
        else
           printf("%d",max_dia);     
    }
    else
        {
            if(max_col>max_dia)
                printf("%d",max_col);
            else
                printf("%d",max_dia);    
        }       
           
   
    
    return 0;
}    
