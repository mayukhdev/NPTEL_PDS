#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

/* Definitions as shown in the lecture */
typedef struct CellType* Position;
typedef int ElementType;

struct CellType
{
    ElementType value;
    Position next;
};

/* *** Implements a List ADT with necessary functions.
You may make use of these functions (need not use all) to implement your HashTable ADT ***/

class List{
    
    private:
        Position listHead;
        int count;
    
    public:
        //Initializes the number of nodes in the list
        void setCount(int num)
        {
            count = num;
        }
        
        //Creates an empty list
        void makeEmptyList()
        {
            listHead = new CellType;
            listHead->next = NULL;
        }        
        
        //Inserts an element after Position p
        int insertList(ElementType data, Position p)
        {
            Position temp;
            temp = p->next;
            p->next = new CellType;
            p->next->next = temp;
            p->next->value = data;    
            return ++count;            
        }        
        
        //Returns pointer to the last node
        Position end()
        {
            Position p;
            p = listHead;
            while (p->next != NULL)
            {
                p = p->next;
            }
            return p;            
        }
        
        //Returns number of elements in the list
        int getCount()
        {
            return count;
        }
};

class HashTable
{
    private:
        List bucket[10];
        int bucketIndex;
        int numElemBucket;
        Position posInsert;
        string collision;
        string tempcol; 
        bool reportCol; //Helps to print a NO for no collisions

    public:
        HashTable()
        { //constructor
            int i;
            for (i=0;i<10;i++)
            {
                bucket[i].setCount(0);
            }
            tempcol = "";
            reportCol = false;
        }
        
        int insert(int data)
        {
            if(bucket[data].getCount()==0)
                {
                    bucket[data].makeEmptyList();
                    posInsert = bucket[data].end();
                    return (numElemBucket = bucket[data].insertList(data,posInsert));
                }
            
            else  if(bucket[data].getCount() >= 1)
                
                    {                                        
                        reportCol = true;
                        posInsert = bucket[data].end();
                        numElemBucket = bucket[data].insertList(data,posInsert);
                        ostringstream ost;
                        ost<<data<<","<<numElemBucket<<")";
                        tempcol = ost.str();                    
                    }
                                                   
                return numElemBucket;
        }
        
        void listCollision(int pos)
        {
                    ostringstream ost;
                    ost<<"("<<pos+1<<",";
                    tempcol = ost.str() + tempcol;
                                  
                    collision = collision +tempcol+" ";     
             
        }
        
        void printCollision();
            
};

int main()
{
    
    HashTable ht;
    int i, data,ifcol;
        
    for (i=0;i<10;i++)
    {
        cin>>data;
        data = data % 10;
        ifcol = ht.insert(data);
        if(ifcol > 1)
                ht.listCollision(i);             
    }

   //Prints the concatenated collision list
   ht.printCollision(); 

}

void HashTable::printCollision(){
    if (reportCol == false)
        cout <<"NO";
    else
        cout<<collision;
}

