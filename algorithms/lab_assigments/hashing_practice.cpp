#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

struct table
{
	int val;
	int parent;
};

int hash_func(int n)
{
	return (n%10 + n/10);
}

void recursively_swap(table tables[],int n,int H,int num,int pos,int parent)
{
     int j = pos-H+1;
     
     if(pos-parent<H)
     {
     	tables[pos].val=num;
     	tables[pos].parent = parent;
         	return;
     }
     for (int i = j; i < pos; ++i)
     {
     	/* code */
     	if(tables[i].parent>pos-H)
     	{
     		swap(tables[i],tables[pos]);
     		recursively_swap(tables,n,H,num,i,parent);
     		return;
     	}
     }
}

void insert(table tables[],int n,int H,int num)
{
     int pos = hash_func(num)%n;
     
     int start = pos;
     while(tables[pos].val!=-1)
     {
     	pos++;
     }
     if(pos<start+H)
     {
     	tables[pos].val=num;
         tables[pos].parent = start;
     }
     else
     {
     	

     	recursively_swap(tables,n,H,num,pos,start);
     }

}

void delete_val(table tables[],int n,int H,int num)
{
	int pos = hash_func(num)%n;

	for (int i = pos; i < pos+H; ++i)
	{
		/* code */
		if(tables[i].val==num)
		{
			tables[i].val = -1;
			return;
		}
	}
}

void print(table tables[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if(tables[i].val!=-1)
			cout<<tables[i].val<<" ";
	}
	cout<<'\n';
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if(tables[i].val!=-1)
			cout<<i<<" ";
	}
}
int main(int argc, char const *argv[])
{
	ifstream input_file;
	ofstream output_file;
	input_file.open("input.txt");
	output_file.open("output.txt");
	
	int n,H;
	input_file>>n>>H;
     
    table tables[n];

    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	tables[i].val=-1;
    }

     

  
	
	
	while(!input_file.eof())
	{
		char type[4];
		int num;
		input_file>>type>>num;
		
		if(type[0]=='i' && type[1]=='n')
		{
		
			for (int i = 0; i < num; ++i)
			{
				/* code */
				int nn;
				input_file>>nn;
				insert(tables,n,H,nn);
			}
				print(tables,n);
			cout<<'\n';
			
		}
		else if(type[0]=='d' && type[1]=='e' && type[2]=='l')
		{
						

				for (int i = 0; i < num; ++i)
			{
				/* code */
				int nn;
				input_file>>nn;
				delete_val(tables,n,H,nn);
			}
				print(tables,n);
			cout<<'\n';
		}
	}

	return 0;
}