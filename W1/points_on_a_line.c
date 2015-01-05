#include<stdio.h>

int main(void)
{
    
    int x1,y1,x2,y2,x3,y3;
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    
    int n = (x1*(y2-y3)) - (y1*(x2-x3)) + ((x2*y3)-(y2*x3));
    
    if(n==0)
        printf("Yes");
    else    
        printf("No");
    
    return 0;
}
