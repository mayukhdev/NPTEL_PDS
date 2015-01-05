#include<stdio.h>
#include<math.h>
//Karatsuba multiplication

int kara(int , int );
int countnum(int );

int main(void)
{
    int m,n,ans;
    
    scanf("%d %d",&m,&n);
    
    ans = kara(m,n);
    printf("%d\n",ans);    
        
    return 0;
}

int kara(int x, int y)
{
   int n1,n2,n,x1,x2,y1,y2,a,b,c; 
   
   n1 = countnum(x);
   n2 = countnum(y);
   
   if(n1>n2)
        n = n2;
   else
        n = n1;      
      
   
   if(n==1)
        return x*y; 
   
   x1 = x/(int)pow(10,n/2);
   x2 = x % (int)pow(10,n/2);
   
   y1 = y/(int)pow(10,n/2);
   y2 = y % (int)pow(10,n/2);
   
   a = kara(x1,y1); 
   c = kara(x2,y2); 
   b = kara(x1+x2,y1+y2) - a - c; 
      
        //printf("return = %d\n",a * (int)pow(10,n)+ b* (int)pow(10,n/2)+c);
   if(n%2==1)
        return a * (int)pow(10,n-1)+ b* (int)pow(10,n/2)+c;
   else
        return a * (int)pow(10,n)+ b* (int)pow(10,n/2)+c;     
   
    
}

int countnum(int x)
{
    int count = 0;
    while(x>0)
    {        
        ++count;
        x/=10;        
    }
    
    return count;
}
