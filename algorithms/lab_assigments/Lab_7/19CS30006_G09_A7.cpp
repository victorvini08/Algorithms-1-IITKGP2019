/*
Aryan Mehta
19CS30006
*/


#include <iostream>
using namespace std;

struct node
{
	int rank;
	node *parent;
};

void makeset(node *x)
{
	 x->parent=x;
	 x->rank=0;
}

node* findset(node *x)
{
	if((x->parent)==x)
		return x;

	x->parent = findset(x->parent);  // path compression

	return x->parent;

}

void mergeset(node *x,node *y)
{
	node *xroot = findset(x);
	node *yroot = findset(y);   //union by rank.

	if (xroot -> rank == yroot -> rank)
	{
		yroot -> parent = xroot;
		xroot -> rank += 1;
	}
	else if (xroot -> rank < yroot -> rank)
		xroot -> parent = yroot;
	else
		yroot -> parent = xroot;
}

void findtreasure(node *x,node *y)
{
	if(findset(x)==findset(y))
		return;

	mergeset(x,y);

}

void printgrid(int *H,int mx,int nx,int *V,int my,int ny)
{

    //Different cases have to be taken because of the output which we have to print. 
	for (int i = 0; i < 2*my+1; ++i)
	{
		for (int j = 0; j < 2*nx+1; ++j)
		{
			if(i==0 && j==1)
			{
				cout<<"   ";
			}
			else if(i%2!=0 && j%2!=0)
				cout<<"   ";
			else if(i==(2*my-1) && j==(2*nx))
			{
				cout<<" ";
			}
			else if(i%2==0 && j%2==0)
			{
				cout<<"+";
			}
			else if(i==0 || i==(2*my))
			{
				cout<<"---";
			}
			else if(j==0 || j==(2*nx))
			{
				cout<<"|";
			}
			else if(i%2==0 && j%2!=0)
			{
				if((*((H+((i-1)/2)*nx) + ((j-1)/2)))==1)
					cout<<"   ";
				else if((*((H+((i-1)/2)*nx) + ((j-1)/2)))==0)
					cout<<"---";
			}
			else if(i%2!=0 && j%2==0)
			{
				if((*((V+((i-1)/2)*ny) + ((j-1)/2)))==1)
					cout<<" ";
				else if((*((V+((i-1)/2)*ny) + ((j-1)/2)))==0)
					cout<<"|";
			}
			             
		}
		cout<<'\n';
	}
}

int main(int argc, char** argv)
{
	srand((unsigned int)time(NULL));
	
	int m=10;
	int n=10;

	if(argc>1)
	{
		m=atoi(argv[1]);
		n=atoi(argv[2]);
	}

	node C[m][n];
	int H[m-1][n];
	int V[m][n-1];



	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			 makeset(&C[i][j]);    // makeset initializes all the disjoint sets.
             
		}
	}
    
	for (int i = 0; i < m-1; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			 H[i][j]=0;
             
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			 V[i][j]=0;
             
		}
	}
    
    int count=0;

    while(findset(&C[0][0])!=findset(&C[m-1][n-1]) || count<(m*n-1))  // condition so that end point is connected to start point and number of steps is not more than m*n-1
    {
    	int num=rand()%2;  // to choose between horizontal or vertical wall
        
        if(num==0)
        {
        	int row= rand()%(m-1);  //randomly choosing row and column
        	int col= rand()%n;
           
        	if(H[row][col]==0 && findset(&C[row][col])!=findset(&C[row+1][col]))  // this ensures fully connected.
        	{

        	findtreasure(&C[row][col],&C[row+1][col]);
            
        	H[row][col]=1;
        	count++;
            }
            
        }
        else if(num==1)
        {
        	int row = rand()%m;
        	int col = rand()%(n-1);
        	          
            if(V[row][col]==0 && findset(&C[row][col])!=findset(&C[row][col+1]))  // this ensures fully connected.
            {
        	findtreasure(&C[row][col],&C[row][col+1]);
        
        		V[row][col]=1;
        		count++;
        	}
        	 
        }
        
    }
     
    if(findset(&C[0][0])==findset(&C[m-1][n-1]))
    {
    	cout<<"Yipeee!The final chamber can be reached from the start chamber."<<endl;
    }
    else
    {
    	cout<<"The final chamber cannot be reached from the start chamber."<<endl;
    }

    int Hinitial[m-1][n];
	int Vinitial[m][n-1];


	for (int i = 0; i < m-1; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			 Hinitial[i][j]=0;
             
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			 Vinitial[i][j]=0;
             
		}
	}
     cout<<'\n';
     cout<<"INITIAL GRID: "<<endl;
     cout<<'\n';
	printgrid((int *)Hinitial,m-1,n,(int *)Vinitial,m,n-1);  //printing initial grid. 
      cout<<'\n';

    
     cout<<"FINAL GRID:"<<endl;
     cout<<'\n';
    printgrid((int *)H,m-1,n,(int *)V,m,n-1);  //printing final grid.


                                       // THANK YOU //

	return 0;
}