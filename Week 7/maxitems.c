#include<stdio.h>
#include<stdlib.h>

int comp (const void * elem1, const void * elem2) 
{
int f = *((int*)elem1);
int s = *((int*)elem2);
if (f > s) return  1;
if (f < s) return -1;
return 0;
}


int getMaxItems(int arr[],int n,int MAX)
{
    int temp=0,i,count=0;    
    //items  = (int*)malloc(sizeof(int)*n);
    
    qsort(arr,n,sizeof(int),comp);	
    
    for(i=0;i<n;i++)
    {
            if((temp + arr[i])<= MAX)
            {
                temp = temp + arr[i];
                count++;
            }
    } 
    
    return count;  
}
/**THE FOLLOWING CODE WILL BE APPENDED TO YOUR CODE BEFORE COMPILATION**/
/**Do not uncomment this code. You should not write main()*/


int main()
{
int n,*arr,MAX,i=0;
scanf("%d",&n);
scanf("%d",&MAX);
arr  = (int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("%d",getMaxItems(arr,n,MAX));
return 0;
}



