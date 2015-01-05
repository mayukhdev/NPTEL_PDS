#include<stdio.h>

void merge(int *a,int i, int mid,int j);
void msort(int *a,int i, int j);

int main (void)
{
    int arr[] = {4,5,12,1,9,5,67,23,333,0};
    
    int n = sizeof(arr)/sizeof(int),i;
    
    for(i=0;i<n;i++)
        printf("%d ",*(arr+i));    
    msort(arr,0,n-1);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",*(arr+i));
    
    

    return 0;
}

void msort(int * a,int i, int j)
{
    int mid ;
    if(i<j)
    {
        mid =  (i+j)/2;
        msort(a,i,mid);
        msort(a,mid+1,j);
        merge(a,i,mid,j);
    }
}

void merge(int *a,int i, int mid,int j)
{
    int temp[100],start,l,k;
    
    l = i;
    k = mid+1;
    start = i;
    
    
    while(i<=mid && k<=j)
    {
        if(a[i]<=a[k])
            temp[l++] = a[i++];
            
        else
            temp[l++] = a[k++];            
    }
    
     if(i>mid)
     { 
       for(;k<=j;) 
        temp[l++]=a[k++];
     }   
   else
        {
        if(k>j)
            {
            for(;i<=mid;) 
                temp[l++] = a[i++];
            }      
        }
    for(l=start ; l<=j ; l++)
        a[l] = temp[l];    
    
    
}











