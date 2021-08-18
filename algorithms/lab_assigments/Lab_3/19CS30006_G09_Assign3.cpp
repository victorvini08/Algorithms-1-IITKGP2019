#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct {
int x, y;
} POINT ;

typedef struct {
POINT *Arr ;
int queue_size;
int start_id;
int end_id;
} QUEUE ;


void init(QUEUE *qp,int size)
{
	qp->queue_size=0;
    qp->Arr = (POINT*)malloc( 
        size * sizeof(POINT)); 
    qp->start_id=0;
    qp->end_id=-1;

}

int isempty(QUEUE qp)
{
   if(qp.queue_size==0)
    return 1;
   else
    return 0;
}

void enqueue(QUEUE *qp,POINT p)
{
   qp->end_id++;
   qp->Arr[qp->end_id]=p;
   qp->queue_size++;

}

POINT dequeue(QUEUE *qp)
{
   qp->queue_size--;

   POINT pop=qp->Arr[qp->start_id];
   qp->start_id++;
   return pop;    

}



 struct STACK {

     POINT head;
     struct STACK *next;

} ;

void initialize_stack(STACK* s)
{
    s= (STACK*)malloc(sizeof(STACK));
    s->head.x=-1;
    s->head.y=-1;
    s->next=NULL;
}

int isempty_stack(STACK* s)
{
   if(s==NULL )
    return 1;
else
    return 0;
}

void push(STACK *s,POINT p)
{
   STACK* st;
   st= (STACK*)malloc(sizeof(STACK));
   st->head=p;
   st->next=s;
   s=st;
}

POINT pop(STACK *s)
{
   STACK *st=s;

  s=s->next;  

   POINT popped;
   popped=st->head;
   free(st);
   return popped;
}
void printgrid(int* array,int A,int B)
{
	cout<<"Grid of Stones is:"<<endl;

	for (int i = 0; i < A; ++i)
	{
		for (int j = 0; j < B; ++j)
		{
			if(*((array+i*B) + j)==1)
				cout<<"-";
			else
				cout<<"*";
		}
		cout<<'\n';
	}
}
int in_bounds(int i,int j,int A,int B)
{
    if(i>=0 && j>=0 && i<A && j<B)
    return 1;
  else
    return 0;
}
int strategy1(int* array,int A,int B,int jx,int jy,int fx,int fy,QUEUE *qp)
{
    POINT starting_point;
    starting_point.x=jx;
    starting_point.y=jy;

    int is_visited[A][B];

    for (int i = 0; i < A; ++i)
    {
        for (int j = 0; j < B; ++j)
        {
            /* code */
            is_visited[i][j]=0;
        }
    }
    is_visited[jx][jy]=1;

    enqueue(qp,starting_point);

    while(!isempty(*qp))
    {
          POINT pop= dequeue(qp);

          if(pop.x==fx && pop.y==fy)
            return 1;
           
           int x_cood=pop.x+1;
           int y_cood=pop.y;
          if(in_bounds(x_cood,y_cood,A,B))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*B) + y_cood)==0)
            {
                 is_visited[x_cood][y_cood]=1;
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 enqueue(qp,curr);
            }
          }
            x_cood=pop.x;
            y_cood=pop.y+1;
          if(in_bounds(x_cood,y_cood,A,B))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*B) + y_cood)==0)
            {
                 is_visited[x_cood][y_cood]=1;
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 enqueue(qp,curr);
            }
          }
            x_cood=pop.x-1;
            y_cood=pop.y;
          if(in_bounds(x_cood,y_cood,A,B))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*B) + y_cood)==0)
            {
                 is_visited[x_cood][y_cood]=1;
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 enqueue(qp,curr);
            }
          }
            x_cood=pop.x;
            y_cood=pop.y-1;
          if(in_bounds(x_cood,y_cood,A,B))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*B) + y_cood)==0)
            {
                 is_visited[x_cood][y_cood]=1;
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 enqueue(qp,curr);
            }
          }
    }

    return 0;    
}

void strategy2(int* array,int A,int B,int jx,int jy,int fx,int fy,STACK *s)
{
     POINT starting_point;
    starting_point.x=jx;
    starting_point.y=jy;

    int is_visited[A][B];

    for (int i = 0; i < A; ++i)
    {
        for (int j = 0; j < B; ++j)
        {
            /* code */
            is_visited[i][j]=0;
        }
    }
     
     push(s,starting_point);

     while(!isempty_stack(s))
     {
         POINT popped= pop(s);

          if(popped.x==fx && popped.y==fy)
          {
            cout<<fx<<" "<<fy<<endl;
            return;
        }
            

         int x_cood=popped.x;
         int y_cood=popped.y;

         if(is_visited[x_cood][y_cood]==0)
         {
            cout<<"("<<x_cood<<","<<y_cood<<")"<<", ";
            is_visited[x_cood][y_cood]=1;
         }
           x_cood=popped.x+1;
           y_cood=popped.y;

         if(in_bounds(x_cood,y_cood,A,B))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*B) + y_cood)==0)
            {
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 push(s,curr);
            }
          }
            x_cood=popped.x;
            y_cood=popped.y+1;
          if(in_bounds(x_cood,y_cood,A,B))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*B) + y_cood)==0)
            {
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 push(s,curr);
            }
          }
            x_cood=popped.x-1;
            y_cood=popped.y;
          if(in_bounds(x_cood,y_cood,A,B))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*B) + y_cood)==0)
            {
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 push(s,curr);
            }
          }
            x_cood=popped.x;
            y_cood=popped.y-1;
          if(in_bounds(x_cood,y_cood,A,B))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*B) + y_cood)==0)
            {
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 push(s,curr);
            }
          }



     }
}
int main()
{
    int A,B,N;
    cin>>A>>B>>N;

    int x[N],y[N];

    for (int i = 0; i < N; ++i)
    {
    	cin>>x[i];
    }
    for (int i = 0; i < N; ++i)
    {
    	cin>>y[i];
    }

    int jx,jy,fx,fy;
    cin>>jx>>jy>>fx>>fy;

    int arr[A][B];

    for (int i = 0; i < N; ++i)
    {
    	arr[x[i]][y[i]]=1;
    }
    for (int i = 0; i < A; ++i)
    {
    	
    	for (int j = 0; j< B; ++j)
    	{
    		if(arr[i][j]!=1)
    			arr[i][j]=0;
    	}
    }

    printgrid((int *)arr,A,B);

    QUEUE qp;
    init(&qp,A*B);
    POINT p;
    p.x=1;
    p.y=2;
   //  // enqueue(&qp,p);
   //  // p.x=3;
   //  // p.y=4;

   //  // enqueue(&qp,p);

   //  // POINT a=dequeue(&qp);
   //  // a=dequeue(&qp);
   //  // cout<<a.x<<" "<<a.y<<endl;

   int ans=strategy1((int *)arr,A,B,jx,jy,fx,fy,&qp);

   if(ans)
   cout<<"Path Exists"<<endl;
   else
    cout<<"No Path Exists"<<endl;

   STACK* s;
   initialize_stack(s);
   push(s,p);
    p.x=3;
    p.y=4;
   push(s,p);
    p.x=5;
    p.y=6;
    push(s,p);
  POINT ans1=pop(s);
       ans1=pop(s);

   cout<<ans1.x<<"  "<<ans1.y<<endl;

 strategy2((int *)arr,A,B,jx,jy,fx,fy,s);


	return 0;
}