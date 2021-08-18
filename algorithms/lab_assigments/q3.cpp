#include "assign2.h"

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
        printf("%d  %d\n",point_array[outputsize].x, point_array[outputsize].y );
        outputsize++; 	
}
Point* merge(Box boxes[],int low,int high,int &outputsize,Point* pint_array)
{
	Point* point_array;
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

  return point_array;
}
Point* solve(Box boxes[],int low,int high,int &outputsize,Point* point_array)
{
		

	if(low==high)
	{
		Point*  point_array;
        Point p;
 
        p.x = boxes[low].left, 
        p.y = boxes[low].ht;
        point_array[outputsize]=p;
        outputsize++;
 
        p.x = boxes[low].right;
        p.y = 0;
        point_array[outputsize]=p;
         
        /*Terminate the recursion and return the result skyline*/
        return point_array;
	}
	else
	{
		int mid=(low+high)/2;
		Point* lef=solve(boxes,low,mid,outputsize,point_array);
		Point* rig=solve(boxes,mid+1,high,outputsize,point_array);

		Point* ans=	merge(boxes,low,high,outputsize,point_array);
;

		return ans;
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