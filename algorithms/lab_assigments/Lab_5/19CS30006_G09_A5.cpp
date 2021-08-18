/*
  
  Definition of subproblem:  The new number is added in such a way such that the ratio of probabilities is maximum.
   
   Base case:
   if i==j:
   dp[i][j]= product of probs such that only 1 taken from each reaction
   else if j<i:
   //Not possible...it means less catalyst amounnt than n.
   dp[i][j]=INF

  REcursion:  

  dp[i][j]=MAX(dp[i][j-1]*maxi,dp[i-1][j-1]*probs[i][0])
  where maxi is the reaction where ratio of prods was max at current point.


*/
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
#define INF -100000.00

int main()
{
	 ifstream input_file;
	ofstream output_file;
	input_file.open("input.txt");
	output_file.open("output.txt");

	int n;
	input_file>>n;
	int c;
	input_file>>c;
	float probs[n+1][c+1];

	for (int i = 1; i <=n; ++i)
	{
		for(int j=1;j<=c;j++)
		{
			float temp;
			input_file>>temp;
			probs[i][j]=temp;
		}
	}

    int count[n+1];

	 float dp[n+1][c+1];
	

	 dp[1][1]=probs[1][1];

	for (int i = 1; i <=n; ++i)
	{
		count[i]=1;
	}

	
		for (int i = 1; i <=n; ++i)
	{
		for(int j=1;j<=c;j++)
		{
			if(i==j && i!=1)
			{
				dp[i][j]=dp[i-1][j-1]*probs[i][1];
			}
			else if(j<i)
			{
				dp[i][j]= INF;
			}
		}
	}

     for (int i = 2; i <=n; ++i)
     {
     	/* code */
     	for(int j=1;j<=c;j++)
     	{   

     		if(j>i)
     		{
               
		 float maxi=-1000.0;
          int max_pos=0;
			for(int k=1;k<=i;k++)
     			{
     				if((probs[k][count[k]+1]/probs[k][count[k]])>maxi)
     				{
     					maxi=probs[k][count[k]+1]/probs[k][count[k]];
     					max_pos=k;
     				}
     			}
     	count[max_pos]++;
     	

     	if((dp[i][j-1]*maxi)>=(dp[i-1][j-1]*probs[i][0]))
     	   {
              dp[i][j]=dp[i][j-1]*maxi;
     	    }
     	    else
     	    {
     	    	dp[i][j]=dp[i-1][j-1]*probs[i][0];
     	    	count[max_pos]--;
     	    	count[i]++;
     	    }
     	}
     	}
     }

    output_file<<dp[n][c]<<endl;

    for (int i = 1; i <=n; ++i)
	{
		/* code */
		output_file<<"reaction "<<i<<" : "<<count[i]<<endl;
	}

   // output_file<<dp[n][c]<<endl;

	// for (int i = 1; i <=n; ++i)
	// {
	// 	if(i<n)
	// 		dp[i]=INF;
	// 	else if(i==n)
	// 	{
	// 	   float prod=1;
	// 	   for(int j=1;j<=n;j++)
	// 	   	prod=prod*probs[j][1];

	// 	   dp[i]=prod;
	// 	}
	// }
	//cout<<dp[3];
	// for (int i = n+1; i <=c; ++i)
	// {
	// 	 float max=-1000.0;
 //          int max_pos=0;
	// 		for(int k=1;k<=n;k++)
 //     			{
 //     				if((probs[k][count[k]+1]/probs[k][count[k]])>max)
 //     				{
 //     					max=probs[k][count[k]+1]/probs[k][count[k]];
 //     					max_pos=k;
 //     				}
 //     			}
 //     	count[max_pos]++;
 //     	dp[i]=dp[i-1]*max;

	// }
	// output_file<<dp[c]<<endl;

	// for (int i = 1; i <=n; ++i)
	// {
	// 	/* code */
	// 	output_file<<"reaction "<<i<<" : "<<count[i]<<endl;
	// }
    
	return 0;
}