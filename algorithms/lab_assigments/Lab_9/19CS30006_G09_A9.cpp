#include <iostream>
#define MAX_SIZE 100

using namespace std;

typedef struct _job {
int jobId;
int startTime;
int jobLength;
int remLength;
} job;

typedef struct _heap {
job list[MAX_SIZE];
int numJobs;
} heap;



void initHeap(heap *H)
{
	H->numJobs = 0;
}

void insertJob(heap *H,job j)
{
	if(H->numJobs==MAX_SIZE)
	{
		cout<<"Sorry! The heap is full."<<endl;
		return;
	}

	H->numJobs++;
	int i = H->numJobs - 1;

	H->list[i] = j;

   
	while(i!=0 && (H->list[i]).remLength<= (H->list[(i-1)/2]).remLength)
	{
		if((H->list[i]).remLength == (H->list[(i-1)/2]).remLength)
		{
			if((H->list[i]).jobId < (H->list[(i-1)/2]).jobId)
			{
				swap(H->list[i],H->list[(i-1)/2]);
				i = (i-1)/2;
			}
			else
				break;
		}
		else
		{
			swap(H->list[i],H->list[(i-1)/2]);
			i = (i-1)/2;
		}
	}
	
	
}

void heapify(heap *H,int i)
{
   int curr = i;
	int left = (2*i)+1;
	int right = (2*i)+2;

	if(left< H->numJobs && (H->list[left]).remLength <= (H->list[curr]).remLength)
	{
		if((H->list[left]).remLength == (H->list[curr]).remLength)
		{
			if((H->list[left]).jobId < (H->list[curr]).jobId)
			{
				curr = left;
			}
		}
		else
		{
		curr = left;
	     }
	}
	if(right< H->numJobs && (H->list[right]).remLength <= (H->list[curr]).remLength)
	{
		if((H->list[right]).remLength == (H->list[curr]).remLength)
		{
			if((H->list[right]).jobId < (H->list[curr]).jobId)
			{
				curr = right;
			}
		}
		else
		{
		curr = right;
	     }
	}
	if(curr!=i)
	{
		swap(H->list[i],H->list[curr]);
	
	heapify(H,curr);
    }
}

job extractMinJob(heap *H)
{
	if(H->numJobs==0)
	{
		cout<<"THE HEAP IS EMPTY!";
	}

	job j = H->list[0];

	H->numJobs--;
	H->list[0] = H->list[H->numJobs];

	heapify(H,0);
  
	return j;
}

void scheduler(job jobList[],int n)
{
   heap H;
   initHeap(&H);

   int time = 0;
   int min_start = jobList[0].startTime;
   for (int i = 1; i < n; ++i)
   {
   	/* code */
   	if(jobList[i].startTime <= min_start)
   		min_start = jobList[i].startTime;
   }
   int flag[100000]={0};  
   	 int count=0;
    cout<<"Jobs scheduled at each timestep are:"<<endl;
    int turn_around_time = 0;
   while(1)
   {
      if(time<min_start)
      {
      	cout<<-1<<" ";
      	time++;
      }
      else
      {
   	
   	  for (int i = 0; i < n; ++i)
   	  {
   	  	/* code */
   	  	if(jobList[i].remLength > 0 && jobList[i].startTime==time)
   	  	{
   	  		
   	  		insertJob(&H,jobList[i]);
   	  		
   	  	}
   	  }
   	  job min_job = extractMinJob(&H);
      cout<<min_job.jobId<<" ";
      
      if(flag[min_job.jobId]==0)
      {
      	turn_around_time+= time -min_job.startTime;
      	flag[min_job.jobId]=1;
      }
    
   	  min_job.remLength--;

   	  if(min_job.remLength>0)
   	  {

   	  	insertJob(&H,min_job);
   	  	

   	  }
   	  else
   	  {
   	  	count++;
   	  }

      time++;
   
     if(count==n)
     	break;
   }
}
    float t = float(turn_around_time)/float(n);
    cout<<'\n';
   cout<<"Average Turnaround Time is  "<< t<<endl;



}
int main()
{
	int n;
	cout<< "ENTER NUMBER OF JOBS (n) : ";
    cin>>n;
    cout<<"ENTER THE JOBS :"<<endl;
    job jobs[n];

    //heap H;

    //initHeap(&H);

    for (int i = 0; i < n; ++i)
    {
    	/* code */
    	int x , y ,z;
    	cin>>x>>y>>z;

    	jobs[i].jobId = x;
    	jobs[i].startTime = y;
    	jobs[i].jobLength = z;
    	jobs[i].remLength = z;
        
        //insertJob(&H,jobs[i]);
    }

    // job min_job;

    // min_job = extractMinJob(&H);

    // cout<<min_job.remLength;

   

    scheduler(jobs,n);


	return 0;
}