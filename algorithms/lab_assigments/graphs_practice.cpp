#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
class Stack
{
   int top;
   public:
   int myStack[MAX]; 
   Stack() 
   { top = -1; }
   void push(int x);
   int pop();
   bool isEmpty();
   int top_item();
};
    void Stack::push(int item)
   {
     myStack[++top] = item;
   }
 
int Stack::pop()
{
   if (top < 0) {
      cout << "Stack is empty!!";
      return 0;
   }
else {
       int item = myStack[top--];
      return item;
   }
}
int Stack::top_item()
{
	if(top<0)
		return 0;
	else
		return myStack[top];
}
 
bool Stack::isEmpty()
{
   return (top < 0);
}




class Queue
{
      int front,rear;
      int queue[MAX];
 
      public:
  
      Queue()
      {
              front=-1;
              rear=-1;
      }
 
       void push(int item)
       {
           
             if(front==-1 && rear==-1)
             {
                      front=rear=0;
                      queue[rear]=item;
             }
             else
             {
                      rear++;
                      queue[rear]=item;
             }
       }
  
       void pop()
       {
              int item;
  
              if(rear==-1)
             {
                       cout<<"\nQUEUE EMPTY";
             }
             else if(front==0 && rear==0)
             {
                       item=queue[front];
                       front=rear=-1;
             }
             else
             {
                      item=queue[front];
                      front++;
             }
       }
 
       int front_item()
       {
              if(front==-1)
              {
                      cout<<"\n\nQUEUE IS EMPTY\n";
              }
              else
              {
                     
                               return queue[front];
                      
              }
        }
};



struct node
{
	int data;
	node* next;
};

struct adjlist
{
	node* head;
};
struct Graph
{
	int n;
	adjlist* array;

};

void addEdge(Graph* graph,int src,int dest)
{
struct node* new_node = new node;   
   new_node->data=dest;
   new_node->next=graph->array[src].head;
   graph->array[src].head=new_node;

//Erase this if graph is directed
 struct node* new_node2 = new node;   
   new_node2->data=src;
   new_node2->next=graph->array[dest].head;
   graph->array[dest].head=new_node2;  

   
}

void printGraph(struct Graph* graph) 
{ 
    int v; 
    for (v = 0; v < graph->n; ++v) 
    { 
        node* pCrawl = graph->array[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->data); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
} 

Graph* createGraph(int n)
{
	struct Graph* graph = new Graph;
	graph->n=n;

	graph->array = new adjlist[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		graph->array[i].head=NULL;
	}
	return graph;
}


int odd_cycle(Graph* graph,int n,int* parent)
{
	Stack s;
	s.push(2);
	int is_visited[n]={0};
	is_visited[2]=1;
    int in_stack[n]={0};
    in_stack[2]=1;
   // int parent[n]={-1};

   while(!s.isEmpty())
   {
          int top= s.top_item();
           int p=s.pop();
           in_stack[p]=0;
       //   cout<<top<<endl;
          node* nod= graph->array[top].head;
          while(nod)
          {
            //cout<<nod->data<<" "<<s.top_item()<<endl;
          	if(is_visited[nod->data]==1 && in_stack[nod->data]==1 && parent[nod->data]!=top)
          		return nod->data;
          	else if(is_visited[nod->data]==0)
          	{
          	is_visited[nod->data]=1;
          	s.push(nod->data);
          	parent[nod->data]=top;
          	in_stack[nod->data]=1;
          }
          	nod=nod->next;
           }
           
          

   }
   return 0;
}

int main()
{
	/* code */
 	int V=5;
 struct Graph* graph = createGraph(V); 
     addEdge(graph, 0, 1); 
     addEdge(graph, 0, 4); 
     addEdge(graph, 1, 2); 
     addEdge(graph, 1, 3); 
     addEdge(graph, 1, 4); 
     addEdge(graph, 2, 3); 
     addEdge(graph, 3, 4); 
  
  // printGraph(graph); 

     int parent[V]={-1};

     int ans=odd_cycle(graph,V,parent);
      int num=ans;
      int count=0;
      // Queue q;
      // q.push(1);
      // q.push(2);
      // cout<<q.front_item()<<endl;
     // while(parent[ans]!=num)
     // {
     // 	cout<<ans<<endl;
     // 	count++;
     // 	ans=parent[ans];
     // }
     //    if(count%2!=0)
     //    	cout<<"Yipee"<<endl;
     //    else
     //    	cout<<"Nopess"<<endl;
    //cout<<ans<<endl;
	return 0;
}