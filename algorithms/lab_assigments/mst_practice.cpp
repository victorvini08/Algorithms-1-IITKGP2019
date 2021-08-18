#include <iostream>
using namespace std;
#define INF 100000


int mindist(int dist[],bool included[],int v)
{
	int min=INF;
    int mino=-1;
   for (int i = 0; i < v; ++i)
   {
   	/* code */
   	if(included[i]==false && dist[i]<min)
   	{
   		min=dist[i];
   		mino=i;
   	}
   }
   return mino;
}
void printSolution(int dist[],int v) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < v; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 

int main()
{
	int v;
	cin>>v;

    int graph[v][v];

    for (int i = 0; i < v; ++i)
        {
        	/* code */
        	for (int j = 0; j < v; ++j)
        	{
        		/* code */
        		int temp;
        		cin>>temp;
        		graph[i][j]=temp;
        	}
        }

        int dist[v];
        bool included[v];

        for (int i = 0; i < v; ++i)
            {
            	/* code */
            	dist[i]=INF;
            	included[i]=false;
            }    
            dist[0]=0;

            for (int i = 0; i < v; ++i)
            {
            	/* code */

            	int min_index = mindist(dist,included,v);
            	included[min_index]=true;

            	for(int j=0;j<v;j++)
            	{
            		if(included[j]==false && graph[min_index][j] && dist[min_index]+graph[min_index][j]<dist[j])
            		{
            			dist[j]=dist[min_index]+graph[min_index][j];
            		}
            	}
            }

             printSolution(dist,v);
            

	return 0;
}