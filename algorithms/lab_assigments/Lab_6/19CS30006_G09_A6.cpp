#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

struct person
{
	int start;
	int end;
	int id;  //id is used to print the correct order in solution.
};


void merge(person people[],int left,int right)
{
	int mid = (left+right)/2;

	

	person people_left[10000],people_right[10000];

	for (int i = 0; i < mid-left+1; ++i)
	{
		/* code */
		people_left[i].start = people[i+left].start;
		people_left[i].end = people[i+left].end;
		people_left[i].id=people[i+left].id;
	}
	for (int i = 0; i < right-mid; ++i)
	{
		/* code */
		people_right[i].start = people[i+1+mid].start;
		people_right[i].end = people[i+1+mid].end;
		people_right[i].id=people[i+1+mid].id;
	}

	int i=0;
	int j=0;
	int k=left;

	while (i < (mid-left+1) && j < (right-mid)) {  
        if (people_left[i].end <= people_right[j].end) {  
            people[k].start = people_left[i].start; 
              people[k].end = people_left[i].end;  
              people[k].id= people_left[i].id;
            i++;  
        }  
        else {  
            people[k].start = people_right[j].start; 
              people[k].end = people_right[j].end; 
              people[k].id = people_right[j].id;   
            j++;  
        }  
        k++;  
    }  
  
   
    while (i < (mid-left+1)) {  
         people[k].start = people_left[i].start; 
          people[k].end = people_left[i].end;  
          people[k].id= people_left[i].id;

        i++;  
        k++;  
    }  
  
   
    while (j < right-mid) {  

        people[k].start = people_right[j].start; 
        people[k].end = people_right[j].end;
        people[k].id = people_right[j].id;   

        j++;  
        k++;  
    }  
}

void sort_array(person people[],int left,int right)
{
	if(left<right)
	{
		int mid = (left+right)/2;

		sort_array(people,left,mid);
		sort_array(people,mid+1,right);

		merge(people,left,right);
	}
}


float schedule_visits(person people[],int n,float current_optima,float min_start)
{
    float current_pos=min_start;
	for (int i = 1; i < n; ++i)
	{
		/* code */
		if(float(people[i].end)<float(current_pos+current_optima))
		{
			current_optima=float(people[i].end- current_pos);
			current_pos = people[i].end;
		}
		else if(float(people[i].start>float(current_pos+current_optima)))
		{
			current_pos=people[i].start;
		}
		else if(float(current_pos+current_optima)>=float(people[i].start) && float(current_optima+current_pos)<=people[i].end)
		{
			current_pos=current_pos+current_optima;
			current_optima=current_optima;
		}

	}
	return current_optima;
}

int main()
{
	 ifstream input_file;
	ofstream output_file;
	input_file.open("input1.txt");
	output_file.open("output1.txt");

	int n;
	input_file>>n;

	person people[n];

	for (int i = 0; i < n; ++i)
	{
		/* code */
		int temp1,temp2;
		input_file>>temp1;
		input_file>>temp2;
		people[i].start=temp1;
		people[i].end=temp2;
		people[i].id= i;
	}
     int min_start=10000;   // min_start is the minimum value of start values of all people.
     int min_finish=10000;
     int min_pos=0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if((people[i].start)<min_start)
		{
			min_start=people[i].start;
			min_finish=people[i].end;
			min_pos=i;
		}
		else if(people[i].start==min_start)
		{
			if(people[i].end<=min_finish)
			{
				min_pos=i;
				min_finish=people[i].end;
			}
		}

	}

	people[min_pos].start=-10000; // so that the person with min start value comes 1st in sorted order.
	people[min_pos].end=-10000;

	sort_array(people,0,n-1);  // sorting the array of structures in increasing order of end time.
    
    int complete_end = people[n-1].end;  // complete end is the max value of all the end values.

    float current_optima = float( min_start + complete_end)/float(n-1);  //current optima will be the value when all people come in equally spaced intervals.

    float final_ans=schedule_visits(people,n,current_optima,float(min_start));

     
    int minutes = int(final_ans);

    float seconds = float(float(final_ans) - float(minutes))*float(60);
    
    int rounded_seconds = int(float(seconds)+0.5);  // rounding off the seconds

    output_file<<minutes<<":";

    if(rounded_seconds<10)
    {
    	output_file<<0<<rounded_seconds<<endl;   //because in output file it is printed 20:00 and not 20:0. Therefore adding a 0.
    }
    else
    	output_file<<rounded_seconds<<endl;


    output_file<<min_pos<<" ";

    for (int i = 1; i < n; ++i)
    {
    	/* code */
    	output_file<<people[i].id<<" ";
    }
    return 0;

}