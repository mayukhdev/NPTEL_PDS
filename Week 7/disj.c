#include<stdio.h>

#include<stdlib.h>

struct Event

{

   int start_time,finish_time;    

};

int comp (const void * elem1, const void * elem2)

{

struct Event  f = *((struct Event*)elem1);

struct Event  s = *((struct Event*)elem2);

if (f.finish_time > s.finish_time) return  1;

if (f.finish_time < s.finish_time) return -1;

return 0;

}


int printMaxActivities(struct Event events[], int n)

{
    int i=0,j=0,*count,ans=0,num=0;
    
    count = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        count[i] = 0;
        
    qsort(events,n,sizeof(struct Event),comp);
    
    int f=0;
    int s=0;
    
    for(i=0;i<n;i++)
    {
        num++;
        for(j=i+1;j<n;j++)
        {
            if(f==0)
            {
                f = events[i].finish_time;
            }
                s = events[j].start_time;
            if(f <= s)
            {
                num++;
                f=events[j].finish_time;//4                
            }                        
        }   
        
        f=0;
        s=0; 
        count[i] = num;  
        num=0;       
    }    
    
    ans = count[0];
    
    
    for(i=1;i<n;i++)
        {
            if(ans<count[i])
                ans = count[i];
        }
      
                     
    return ans;
  
}

/**THE FOLLOWING CODE WILL BE APPENDED TO YOUR CODE BEFORE COMPILATION**/
/**Do not uncomment this code. You should not write main()*/

int main()

{

   int n,count,i;

   scanf("%d",&n);

   struct Event *events = (struct Event *)malloc(n*sizeof(struct Event));

   for(i=0;i<n;i++)

       scanf("%d",&events[i].start_time);

   for(i=0;i<n;i++)

       scanf("%d",&events[i].finish_time);

   count = printMaxActivities(events,n);

   printf("%d",count);

    return 0;

}


