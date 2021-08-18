#include<stdio.h>
typedef struct  {
	// x coordinate of left side
	int left;
	// height
	int ht;
	// x coordinate of right side
	int right;
} Box;

// A Point in Outline
typedef struct  {
	// x coordinate
	int x;
	// height or the y coordinate
	int y;
} Point;

Point* findOutLine(Box boxes[], int size, int &outputsize);
void prettyPrint(Point* points, int outputsize) {
	int i;
	printf(" OutLine for given Boxes is \n[");
	for (i = 0; i < outputsize; i++) {

		printf(" (%d, %d), ", points[i].x, points[i].y);

	}
	printf("\b\b ]\n");
}
void process() {
	int n;
	scanf("%d", &n);
	Box boxes[n];
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &boxes[i].left , &boxes[i].right , &boxes[i].ht);
	}
	int outputsize;
	Point* ptr = findOutLine(boxes, n, outputsize);

	prettyPrint(ptr, outputsize);
}







void append(Point* point_array,int &outputsize,int x_cood,int y_cood)
{
	    if(outputsize!=0)
	    {
        if (point_array[outputsize - 1].y == y_cood) 
            return; 
        else if (point_array[outputsize-1].x == x_cood) { 
        	if(point_array[outputsize - 1].y>=y_cood)
            point_array[outputsize - 1].y = point_array[outputsize - 1].y;
            else
               point_array[outputsize - 1].y =y_cood;
            return; 
        } 
    }
  
        point_array[outputsize].x =x_cood;
        point_array[outputsize].y=y_cood; 
        //printf("%d  %d\n",point_array[outputsize].x, point_array[outputsize].y );
        outputsize++; 	
}
void merge(Box boxes[],int low,int high,int &outputsize,Point* point_array)
{
	int mid=(low+high)/2;

	int i=0;
	int j=mid+1;

	int a=0;
	int b=0;

	while(i<=mid && j<=high)
	{
		if(boxes[i].left<boxes[j].left)
		{
           a=boxes[i].ht;
              
              if(a>=b)
             append(point_array,outputsize,boxes[i].left,a);
         else
         	append(point_array,outputsize,boxes[i].left,b);
			i++;
		}
		else
		{ 
			b= boxes[j].ht;
           if(a>=b)
             append(point_array,outputsize,boxes[j].left,a);
         else
         	append(point_array,outputsize,boxes[j].left,b);
			j++;
		}
	}
	while(i<=mid)
	{
	  append(point_array,outputsize,boxes[i].left,boxes[i].ht);

		i++;
	}
	while(j<=high)
	{
     append(point_array,outputsize,boxes[j].left,boxes[j].ht);

		j++;
	}

}

void solve(Box boxes[],int low,int high,int &outputsize,Point* point_array)
{
		

	if(low==high)
	{
		append(point_array,outputsize,boxes[low].left,boxes[low].ht);
		append(point_array,outputsize,boxes[low].right,0);
	}
	else
	{
		int mid=(low+high)/2;
		solve(boxes,low,mid,outputsize,point_array);
		solve(boxes,mid+1,high,outputsize,point_array);

		merge(boxes,low,high,outputsize,point_array);
	}
}
Point* findOutLine(Box boxes[],int size,int &outputsize)
{
	Point* point_array;
	outputsize=0;


    solve(boxes,0,size-1,outputsize,point_array);  

	return point_array;

}

int main()
{

	process();


	return 0;
}