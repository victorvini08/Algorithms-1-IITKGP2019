#include <iostream>

using namespace std;


class max_heap_class
{
	int size;
	int capacity;
	int *array;
public:
      
     int parent(int i)
      {
      	return (i-1)/2;
      }
      max_heap_class(int capacity)
      {
      	capacity = capacity;
      	array = new int[capacity];
          size =0 ;
       };

      void insert(int val)
      {
      	if(size==capacity)
      		cout<<"Nopes!";
      	else
      	{
      		size++;      		
            int i = size-1;
            array[i]=val;
      		while(i!=0 && array[parent(i)]<array[i])
      		{
      			swap(array[parent(i)],array[i]);
      			i=parent(i);
      		}
      	}
      }

void heapify(int i)
{
	int largest = i;
	int l = (2*i)+1;
	int r = (2*i)+2;

	if(l<size && array[l]>array[largest])
	{
		largest = l;
	}
	if(r<size && array[r]>array[largest])
	{
		largest = r;
	}
	if(largest!=i)
	{
		swap(array[i],array[largest]);
	
	heapify(largest);
    }
}

      int extract_max()
      {
      	   int ans = array[0];
           size--;

           array[0]=array[size];

           heapify(0);

           return ans;
      }


	
	
};

// void heapify(int arr[],int n,int i)
// {
// 	int largest = i;
// 	int l = (2*i)+1;
// 	int r = (2*i)+2;

// 	if(l<n && arr[l]>arr[largest])
// 	{
// 		largest = l;
// 	}
// 	if(r<n && arr[r]>arr[largest])
// 	{
// 		largest = r;
// 	}
// 	if(largest!=i)
// 	{
// 		swap(arr[i],arr[largest]);
	
// 	heapify(arr,n,largest);
//     }
// }



// void max_heap(int a[],int n)
// {
// 	int non_leaf = (n/2) -1;

// 	for(int i = non_leaf;i>=0;i--)
// 	{
// 		heapify(a,n,i);
// 	}
// }

// void insert(int a[],int n,int val)
// {

// }  


int main()
{
	int n;
	cin>>n;
	int a[n];
    max_heap_class h(15);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>a[i];
		h.insert(a[i]);
	}

	cout<< h.extract_max();
	
	return  0;
}