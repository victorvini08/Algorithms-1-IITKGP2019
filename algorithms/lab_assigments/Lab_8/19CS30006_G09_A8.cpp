#include <iostream>

using namespace std;


struct POINT{
int x, y;
   POINT *parent;
};

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

int in_bounds(int i,int j,int n)
{
    if(i>=0 && j>=0 && i<n && j<n)
    return 1;
  else
    return 0;
}

int printpath(QUEUE *qp)
{
	if(qp==NULL)
		return 0;

	while(!isempty(*qp))
	{
		POINT pop=dequeue(qp);
	cout << "(" << pop.x << ", " << pop.y << ") ";
	
    }
	return 1;
}

int bfs(int *array,int n,int sx,int sy,int fx,int fy,QUEUE *qp,int time)
{
    POINT starting_point;
    starting_point.x=sx;
    starting_point.y=sy;

    int is_visited[n][n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            /* code */
            is_visited[i][j]=0;
        }
    }
    is_visited[sx][sy]=1;

    enqueue(qp,starting_point);
    starting_point.parent=NULL;

    while(!isempty(*qp))
    {
    	  int flag=0;
    	  
          POINT pop= dequeue(qp);

          if(pop.x==fx && pop.y==fy)
          {
         	
            return 1;
        }
           
           int x_cood=pop.x+1;
           int y_cood=pop.y;
          if(in_bounds(x_cood,y_cood,n))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*n) + y_cood)<=time)
            {
                 is_visited[x_cood][y_cood]=1;
                 *((array+x_cood*n) + y_cood)=time;
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 curr.parent=&pop;
                 enqueue(qp,curr);
            }
          }
            x_cood=pop.x;
            y_cood=pop.y+1;
          if(in_bounds(x_cood,y_cood,n))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*n) + y_cood)<=time)
            {
                 is_visited[x_cood][y_cood]=1;
                 *((array+x_cood*n) + y_cood)=time;
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 curr.parent=&pop;
                 enqueue(qp,curr);
            }
          }
            x_cood=pop.x-1;
            y_cood=pop.y;
          if(in_bounds(x_cood,y_cood,n))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*n) + y_cood)<=time)
            {
                 is_visited[x_cood][y_cood]=1;
                 *((array+x_cood*n) + y_cood)=time;
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 curr.parent=&pop;
                 enqueue(qp,curr);
            }
          }
            x_cood=pop.x;
            y_cood=pop.y-1;
          if(in_bounds(x_cood,y_cood,n))
          {
            if(is_visited[x_cood][y_cood]==0 && *((array+x_cood*n) + y_cood)<=time)
            {
                 is_visited[x_cood][y_cood]=1;
                 *((array+x_cood*n) + y_cood)=time;
                 POINT curr;
                 curr.x=x_cood;
                 curr.y=y_cood;
                 curr.parent=&pop;
                 enqueue(qp,curr);
            }
          }

        
    }

    return 0;    
}


int main()
{
   int n;
   cin>>n;
   int graph[n][n];

   for (int i = 0; i < n; ++i)
   	{
   		/* code */
   		for(int j=0;j<n;j++)
   		{
   			int temp;
   			cin>>temp;

   			graph[i][j]=temp;
   		}
   	}

   	int sx,sy,fx,fy;

   	cin>>sx>>sy>>fx>>fy;

   	int time=0;	
     
      QUEUE qp;
    init(&qp,n*n);
   
    while(true)
    {
    int ans=bfs((int *)graph,n,sx,sy,fx,fy,&qp,time);

    if(ans==0)
    	time++;
    else
    {
    	cout<<"Minimum time taken is: "<<time<<endl;
    	break;
    }
    }
    return 0;
   }
