#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

struct node
{
	int key;
	node *left,*right;
};

node* preorder_to_bst(int a[],node*head,int low,int high)
{
	cout<<head->key<<endl;
   	if(low==high)
   	{
   		if(a[low]>head->key)
   		{
   			node* temp= new node;
   			temp->key=a[low];
   			temp->left=NULL;
   			temp->right=NULL;
   			head->right=temp;
   			head->left=NULL;
   			return head;
   		}
   		else
   		{
   			node* temp= new node;
   			temp->key=a[low];
   			temp->left=NULL;
   			temp->right=NULL;
   			head->left=temp;
   			head->right=NULL;
   			return head;
   		}
   	}
   	else
   	{


   	head->key=a[0];

   	int min=1000000;
   	int min_pos=1000000;
   	for (int i = low+1; i <=high; ++i)
   	{
   		/* code */
   		if(a[i]<min && a[i]>a[low])
   		{
   			min=a[i];
   			min_pos=i;
   		}

   	}
   	head->left= preorder_to_bst(a,head,low+1,min_pos-1);
   	head->right= preorder_to_bst(a,head,min_pos,high);

   	return head;
   }
   
}
node* insert(node* head,int data)
{
    if(head==NULL)
    {
    	node* n= new node;
    	n->key=data;
    	n->left=NULL;
    	n->right=NULL;
    	return n;
    }
    else
    {
    	node* temp = head;
        node* t;
    	while(temp!=NULL)
    	{
    		t=temp;
    		if(data==temp->key)
    			return head;
    		else if(data<temp->key)
    		{
    			temp=temp->left;
    		}
    		else
    		{
    			temp=temp->right;
    		}
    	}
    	node* n = new node;
    	n->key=data;
    	n->left=NULL;
    	n->right=NULL;
        if(data>t->key)
        {
          t->right=n;
        }
        else
        	t->left=n;
        return n;
    }
}

void inorder(node* head)
{
	if(head!=NULL)
	{
		inorder(head->left);
		cout<<head->key<<endl;
		inorder(head->right);
	}
}

int main()
{
	/* code */
	// node* head = NULL;
	// head=insert(head,50);
	//  cout<<head->key<<endl;
	//  insert(head,70);
	//  insert(head,40);

	node* head= new node;

	int a[]=  {10, 5, 1, 7, 40, 50};
    
	int n=6;

	node* ans= preorder_to_bst(a,head,0,n-1);

	 inorder(ans);
	return 0;
}