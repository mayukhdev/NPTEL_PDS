#include <iostream>

using namespace std;

class binarySearchTree;
class treeNode
{
	/*
	*with the following friend declaration
	*binarySearchTree class can also access private members of treeNode
	*/
	friend class binarySearchTree;
	private:
		int data;
		treeNode * left;
		treeNode * right;
	
	public:
		treeNode(){
			left=right=NULL;
			//parent = NULL;
		}
		treeNode(int key){
			data=key;
			left=right=NULL	;
			//parent=NULL;
		}
		int getData(){ return data;}
		void setData(int key){data=key;}
};

class binarySearchTree
{
	private:
		treeNode * root;
	public:
		binarySearchTree(){root=NULL;}

/*THE ABOVE CODE WILL BE ADDED AS PREFIX TO YOUR CODE**/
/*Finish The Implementation of the binarySearchTree Class*/
        
       void insert(int n)
       {
            treeNode *place = search(root,n);
            
            if(place==NULL)
                root = new treeNode(n); 
            
            else
                if((place->data)> n)
                         place->left= new treeNode(n);

            else
                if((place->data) < n)                   
                    place->right= new treeNode(n);

       }
       
       void remove(int n)
       {
       
             treeNode * parent,*place,*min,*temp;

                temp = root;                
                
            parent = findparent(temp,n,temp);

            place = search(temp,n);

        if(((place->left)==NULL) && ((place->right)==NULL)) //No child
        {

            if((parent->data)> n)
            {
                 parent->left = NULL;
                 delete (parent->left);
            }

           else
            if((parent->data) < n)
            {
                parent->right = NULL;
                delete (parent->right);
            }
        }
       else
        if(((place->left)==NULL) && ((place->right)!=NULL))//only right child
              {
                if((parent->left) == place)
                    parent->left = place->right;
                else
                    parent->right = place->right;

                delete (place);
              }

       else
        if(((place->left)!=NULL) && ((place->right)==NULL))//only left child 
            {
                if(parent->left == place)
                    parent->left = place->left;
                else
                    parent->right = place->left;

                delete (place);
            }
       else
         if(((place->left)!=NULL) && ((place->right)!=NULL))//both childs exist
            {
                min = find_min(place->right);
                //printf("Min-%d\n",min->data);

                treeNode* min_parent = findparent(place->right,min->data,place->right);
                if (min_parent->data == min->data)
                	min_parent = place;
                //printf("Parent-%d\n",min_parent->data);
                n = min->data;

                    if(((min->left)==NULL) && ((min->right)==NULL)) //No child
                        {
                            if((min_parent->data)> n)
                            {
                                min_parent->left = NULL;
                                delete (min_parent->left);
                            }

                        else
                            if((min_parent->data) < n)
                            {
                                min_parent->right = NULL;
                                delete (min_parent->right);
                            }
                        }

                    else
                     if(((min->left)==NULL) && ((min->right)!=NULL))
                        {
                           if(min_parent->left == min)
                                min_parent->left = min->right;
                           else
                                min_parent->right = min->right;

                                delete (min);
                        }

                    else
                     if(((min->left)!=NULL) && ((min->right)==NULL))
                      {
                            if(min_parent->left == min)
                                min_parent->left = min->left;
                            else
                                min_parent->right = min->left;

                                delete (min);
                      }
            	place->data = min->data;
                }  
       }
       
       void postprint(treeNode * temp)
       {
            
            if(temp)
            {
                postprint(temp->left);
                postprint(temp->right);
                cout<<temp->data<<" ";
            }
                
       }
       
        void print()
       {
       	    if(root==NULL)
                cout<<"NULL";		
            postprint(root);        
       }
      
      treeNode * search(treeNode * temp , int k)
      {
           if(temp == NULL)
                return temp;

        else
        if((temp->data) == k)
                return temp;

        else
        if((temp->data)>k)
            {
                if(temp->left==NULL)
                    return temp;

                else
                    return search(temp->left,k);
             }

       else
            {
                if(temp-> right==NULL)
                    return temp;

                else
                    return search(temp->right,k);
            }
        
        }
        
       treeNode * findparent(treeNode * temp , int n,treeNode * parent)
       {
            if(temp == NULL)
            {
                parent = temp;
                return parent;
            }

        else
            if((temp->data) == n)
                return parent;

        else
            {
                if((temp->data)>n)
                    return findparent(temp->left,n,temp);


                else
                //if((temp->data)<n)
                    return findparent(temp->right,n,temp);
         }    
       } 

    treeNode* find_min(treeNode* temp)
    {
        if(temp->left==NULL)
            return temp;
        else
            return find_min(temp->left);
    }

};            
       

/**Prefixed code **/
/*implement the insert, remove and print functions inside *binarySearchTree class and close the class declaration.
*/
/**Write Your Code Here**/

/**THE FOLLOWING CODE WILL BE APPENDED TO YOUR CODE BEFORE COMPILATION**/
/**Do not uncomment this code. You should not write main()*/

int main(void)
{
	
	binarySearchTree bst;
	int N,val,k;
	char op;
	cin>>N;
	while(N--){
		cin>>val;
		bst.insert(val);
	}
	cin>>k;

	while(k--){
		cin>>op;
		cin>>val;

		if(op == 'i'){
			bst.insert(val);
		}
		else if (op=='d'){
			bst.remove(val);
		}

	}
	
	//print post order traversal of the tree
	bst.print();

	return 0;
}			


