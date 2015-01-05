#include<stdio.h>

void sort(int *a,int n);
void search(int first,int last,int key,int *a);

int main (void)
{
    int n,fin=231;
    int arr[] = {5,3,1,151,53,78,3,2,4,5,2341};
    n = sizeof(arr)/sizeof(int);    
    int * new = arr;
    
    sort(new,n);
    
    int first = 0;
    int last = n-1;    
    search(first,last,fin,new);
    
    return 0;
}

void sort(int *a,int n)
{
    int i,j,key;    
    
    for(j=1;j<n;j++)
    {
        key = a[j];
        i = j-1;
        
        while(i>=0 && a[i] > key)
        {

            a[i+1] = a[i];
            i = i-1;
             
        } 
        
        a[i+1] = key;  
    }
}

void search(int first,int last,int key,int *a)
{
   
    if(first>last)
        printf("NOT found\n");
    else
        {

            int mid = (first+last)/2;
            
            if(a[mid] == key)
                printf("Found\n");
            else
                {
                    if(key>mid)
                        search(mid+1,last,key,a);
                    else
                        search(first,mid-1,key,a);
                }
        }
             
}                









