#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
    int a[10000],i=0,x=0;

    a[0]= 1;
	int count=1;
    int *first;
    first = a;

	do
    {
		count=count+1;
		x = *first;
		a[i] = 2*x;
		a[i+1] = 2*x+1;
		first = &a[i];
	}while(x != 967);

	cout<<count<<endl;

    return 0;
}
