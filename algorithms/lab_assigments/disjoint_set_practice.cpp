#include <iostream>
#include <fstream>
using namespace std;
#include <bits/stdc++.h>
struct disjoint_set
{
   pair <int,int> parent;
   int rank;
   int value;
};

pair <int,int> find(int i,int j,int n,disjoint_set sets[n][n])
{
	if(make_pair(i,j)==sets[i][j].parent)
	{
		return sets[i][j].parent;
	}

	sets[i][j].parent = find(i,j,n,sets);

	return sets[i][j].parent;
}

void union_set(int i,int j,int i2,int j2,int n,disjoint_set sets[n][n])
{
	if(find(i,j,n,sets)==find(i2,j2,n,sets))
		return;

	if(sets[i][j].rank<sets[i2][j2].rank)
	{
		sets[i2][j2].parent = sets[i][j].parent;
	}
	else
	{
		sets[i][j].parent= sets[i2][j2].parent;

		if(sets[i][j].rank==sets[i2][j2].rank)
			sets[i2][j2].rank++;
	}
}
int main()
{
    int n;
    cin>>n;

    int inp[n][n];
    disjoint_set sets[n][n];
    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	for (int j = 0; j < n; ++j)
    	{
    		/* code */
    		cin>>inp[i][j];
    		sets[i][j].parent= make_pair(i,j);
    		sets[i][j].rank = 0;
    		sets[i][j].value = inp[i][j];
    	}
    }

    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	for (int j = 0; j < n; ++j)
    	{
    		/* code */
    		if(i==0 && j==0)
    		{
    			sets[i][j].value=inp[i][j];
    		}
    		else if(i==0)
    		{
    			if(sets[i][j].value==sets[i][j-1].value)
    			union_set(i,j,i,j-1,n,sets);
    		}
    		else if(j==0)
    		{
                 if(sets[i][j].value==sets[i-1][j].value)
    			union_set(i,j,i-1,j,n,sets);
    		}
    		else
    		{
    		      if(sets[i][j].value==sets[i][j-1].value)
    			union_set(i,j,i,j-1,n,sets);
    			else if(sets[i][j].value==sets[i-1][j].value)
    			union_set(i,j,i-1,j,n,sets);
    		}

    	}
    }
	return 0;
}