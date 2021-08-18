#include <bits/stdc++.h>
using namespace std;
#define cp ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int  
#define vint vector<int>
#define vllint vector<ll>
#define pair_int pair<int , int>
#define vector_of_pair_int vector<pair_int>
#define pb push_back 
#define test_case int t; cin>>t; while(t--)
#define umap unordered_map <ll,ll> 
#define mapint map<int,int>
#define infinity 1000000000
#define mp make_pair
#define SIZE 1000000


// class STACK
// {
//     private:
//         int num[SIZE];
//         int top;
//     public:
//         STACK();    //defualt constructor
//         int push(int);
//         int pop();
//         int isEmpty();
        
        
// };
// STACK::STACK(){
//     top=-1;
// }
 
// int STACK::isEmpty(){
//     if(top==-1)
//         return 1;
//     else
//         return 0;   
// }
 
// void STACK::push(int n){
   
//     ++top;
//     num[top]=n;
// }
 
// int STACK::pop(){
  
//     int temp;
//     if(isEmpty())
//         return 0;
//     temp=num[top];
//     --top;
//     return temp;
     
// }
 
class Queue
{
      int front,rear;
      int queue[SIZE];
 
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


struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}



void dfs_recursive(vint neigh[],vint &ans,int i,int is_visited[])
{
	if(is_visited[i]==1)
		return;
    else
    {
    	is_visited[i]=1;
    	ans.pb(i);

    	for(auto el:neigh[i])
    	{
    		if(is_visited[el]==0)
    		dfs_recursive(neigh,ans,el,is_visited);
    	}
    }
    
}

vint dfs(int n,vint adj[])
{
  
  int is_visited[n]={0};
  vint ans;


   for (int i = 0; i < n; ++i)
   {
   	/* code */
   	 if(is_visited[i]==0)
   	 {
   	    dfs_recursive(adj,ans,i,is_visited);
        

      

   	    }
   }
   return ans;



}

vint bfs(int n,vint adj[])
{
	int is_visited[n]={0};
     vint ans;
	queue<int> q;
	q.push(0);
	int i;
	is_visited[0]=1;
  while(!q.empty())
  {
  	/* code */
  	int top=q.front();
  	q.pop();

    ans.pb(top);
    i =top;
  	if(is_visited[i]==0)
  	{
  		is_visited[i]=1;
  		q.push(i);
}
  		for(auto el:adj[i])
  		{
  			if(is_visited[el]==0)
  			{
  				is_visited[el]=1;
  				q.push(el);
  			}
  		



  	}
  }
  return ans;
}

 bfs_in_c(int n,int adjacency[n][])
 

// int cycle_detection(int n,vint adj[])
// {
// 	stack<int> s;
// 	int val_stack[10000]={0};
// 	int is_visited[n]={0};
// 	s.push(0);
// 	is_visited[0]=1;
// 	val_stack[0]

// 	for (int i = 0; i < n; ++i)
// 	{
// 		/* code */
//         if(is_visited[i]==0)
//         {
//           cycle_detection_recursive(i,adj,is_visited);     
//         }
// 	}
// }
void topological_sort_recursive(int n,vint adj[],stack<int> &s,int i,int is_visited[])
{
	is_visited[i]=1;

	for(auto el:adj[i])
	{
		if(is_visited[el]==0)
		topological_sort_recursive(n,adj,s,el,is_visited);
	}
    s.push(i);

}

void topological_sort(int n,vint adj[])
{
	int is_visited[n]={0};
	stack<int> s;
	vint ans;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if(is_visited[i]==0)
			topological_sort_recursive(n,adj,s,i,is_visited);


	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main() 
{ 
	cp
   
    	int n,e;
    	cin>>n>>e;

    	vint vec;
    	vint adj[n];

    	int adjacency[n][n];

    	for (int i = 0; i < e; ++i)
    	{
    		/* code */
    		int u,v;
    		cin>>u>>v;
             adj[u].pb(v);
             adjacency[u][v]=1;
             adjacency[v][u]=1;
           //  adj[v].pb(u);  For directed graphs is is commented,otherwise uncomment it!
    	}
    

      //vint ans=bfs(n,adj);

//       for(auto el:ans)
//       {
//       	cout<<el<<" ";
//       }
// cout<<'\n';
      topological_sort(n,adj);

      bfs(n,adjacency);

 
  
    return 0; 
} 