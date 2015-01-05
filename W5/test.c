#include <stdio.h>
#define MAX 10000

int dequeue();
void enqueue(int n);

int a[MAX],last=0,first=0;

int main(void)
{
    int i,x=0;
    
    for(i=0;i<MAX;i++)
        a[i] = 0;
           

    enqueue(1);
	int count=1;

	do
    {
		count=count+1;
		                  x = dequeue();
		                  enqueue(2*x);
		                  enqueue(2*x+1);
		
				
	}while(x != 967);

	printf("%d\n",count);

    return 0;
}

int dequeue()
{
    int temp = a[first];
    first = first+1;
    return temp;
}

void enqueue(int n)
{
    a[last] =  n;
    last = last +1;             
}
