#include<iostream>
#include <stdlib.h>
using namespace std;

class IntStack {
	private:
		int *Data;
		int MAX_SIZE;
		int top;
	public: 
		IntStack(){
			top=-1;
			MAX_SIZE = 50;
			Data = new int[MAX_SIZE];
		}
		IntStack(int size) {
			top=-1;
			MAX_SIZE=size;
			Data=new int[MAX_SIZE]; 
		} 
		int isfull() {
			if(top==(MAX_SIZE-1)) return 1;
			else return 0; 
		} 
		int isempty() {
			if(top==-1) return 1; 
			else return 0; 
		} 
		int topData() {
			if(isempty()){
				cerr<<"Error:Stack Underflow"<<endl;
				return -1;
			}
			else return Data[top];
		} 
		void push(int elem) {
			if (isfull()){
				cerr<<"Error:Stack is Full"<<endl;
			}
			else{
				Data[++top] = elem;
			}
		} 
		int pop() {
			if(isempty()){
				cerr<<"Error:Stack Underflow"<<endl;
				return -1;
			}
			else {
				return Data[top--];
			}
		}
};
/***END OF FIXED PREFIX CODE **/

#include<ctype.h>
#define NUMBER '0'


int getop(char s[])
{
	int i,c;
	
	c=cin.get();	
	
	while((s[0]=c) == ' ')
	;
	
	s[1] = '\0';
	
	if(!isdigit(c))
		return c;
		
		cout<<c<<" ";
	i = 0;	
		
	if(isdigit(c))
		while(isdigit(s[++i] = cin.get()));
		
	s[i]='\0';

	
	return NUMBER;
}

int main()
{
   int n,i,num,v1,v2,type;
   IntStack s1;

   char s[50];
   
   cin>>n;
   
   for(i=0;i<n;i++)
   {
       type=getop(s);             
        
        switch(type)
        {
            case NUMBER:
                    s1.push(atoi(s));
                    break;
                    
            case '+':
                    v2 = s1.pop();
                    v1 = s1.pop(); 
                    s1.push(v1 + v2);                   
                    break;
            
            case '-':
                    v2 = s1.pop();
                    v1 = s1.pop(); 
                    s1.push(v1 - v2);                                       
                    break;
            
            case '*':
                    v2 = s1.pop();
                    v1 = s1.pop(); 
                    s1.push(v1 * v2);                                                      
                    break;
            
            case '/':
                    v2 = s1.pop();
                    v1 = s1.pop(); 
                    s1.push(v1 / v2); 
                    break;
        }
                
        
   }
   
   cout<<s1.pop();	
	
   return 0;
}
