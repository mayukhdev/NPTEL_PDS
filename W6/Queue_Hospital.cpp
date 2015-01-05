#include <iostream>
using namespace std;

struct Node{
        int info;
	Node *next;
};

class QueueADT{
	private:		
		Node *qFront;
		Node *qRear;
		
	public:
		QueueADT(){ //constructor
			qFront = 0;
			qRear = 0;		
		}		
 		bool isEmpty()
 		{
			if (qFront==NULL) return(true); 
			else return(false);
		}		
 		int dequeue(){	 	    	
 			int data;
 			data = qFront->info;
			qFront = qFront->next;
			if (qFront==0) qRear = 0;
			return data;
 		}		
 		void enqueue(int data){
 			Node *temp = new Node();    
 			temp->info = data;          
			temp->next = NULL;             
			
			if (qFront == 0) {
 				qFront = qRear = temp;
 			}
			else{
				qRear->next = temp;
 				qRear = temp;
			 }
		}		
		
};

int main(){
	int i, token, priority,temp;
	QueueADT q1, q2, q3, q4;

	for (i=0;i<10;i++)
	{
		cin>>token>>priority;
		
		if(priority == 1)
		{
		       q1.enqueue(token);
		       //++c1;
		}
		else if(priority == 2)
		{
		       q2.enqueue(token);
		       //++c2;       
		}
		else if(priority == 3)
		{ 
		      q3.enqueue(token);                                        /* Write code here to populate three queues for separate priorities */
              //++c3;  
        }                                                                
    }
    
    while(q1.isEmpty()==false || q2.isEmpty()==false || q3.isEmpty()==false)
    {
        for(i=0;q1.isEmpty()==false && i <3;i++)
        {
            temp = q1.dequeue();
            q4.enqueue(temp);
        }  
        
        for(i=0;q2.isEmpty()==false && i <2;i++)
        {
            temp = q2.dequeue();
            q4.enqueue(temp);
        }
        
        for(i=0;q3.isEmpty()==false && i <1;i++)
        {
            temp = q3.dequeue();
            q4.enqueue(temp);
        } 
           
    }   
        /* Write code here to remove items from the three queues 
           based on the procedure specified, and add the "dequeued" 
           elements to queue q4, which will be printed using 
           non-editable loop given below */

/* DO NOT edit the code below. It will be appended during compilation*/

	for (i=0;i<10;i++)
		cout<<q4.dequeue()<<" ";
}


