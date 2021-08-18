#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

struct node
{
	int data;
	node *add;
};

node* XOR (node *a, node *b)  
{  
    return (node*)((uintptr_t) (a) ^ (uintptr_t) (b));  
} 

void add_new_node(node **head, int num, node **tail)
{
	node *new_node = new node();
	new_node->data= num;

	if ((*head)== NULL && (*tail)==NULL)  
    {  
    	 new_node->add = NULL;

        *head=new_node;
        *tail=new_node; 
    }  
    else
    {
    	 new_node->add = XOR(*tail, NULL);
        (*tail)->add = XOR((*tail)->add, new_node);

          *tail=new_node;      

    }



        
}
void traverse_from_front_to_end (node *head)  
{  
    node *curr = head;  
    node *prev = NULL;  
    node *next;  
  
  
    while (curr != NULL)  
    {  
        cout<<curr->data<<" ";  
  
      
        next = XOR (prev, curr->add);  
  
        prev = curr;  
        curr = next;
    }  
}  

void traverse_from_end_to_front (node *curr, node *prev)  
{ 
   if(curr !=NULL)  
   {
       cout<< curr->data<<" ";
       traverse_from_end_to_front(XOR(curr->add, prev),curr);
    
   }
  
  
}  


void reverse ( node **head, node **tail)
{
        node *tmp= *head;
        *head= *tail;
        *tail=tmp;

   
}

void alternate ( node **head, node **tail)
{

  if ((*head) != (*tail) && (*head)->add!=(*tail)) { 
        node* tmp = XOR((*head)->add,(*head)); 
        node *t=XOR((*head)->add,(*head));
         t= *tail; 
         node *s =  XOR((*tail)->add,(*tail));
         s   = tmp; 
        *head = tmp; 
    } 
    else { 
        if ((*head) != *tail) 
            *head = XOR((*head)->add,(*head)); 
        (*head)->add = NULL; 
    } 

}
int main()
{
   int n;
   cin>>n;

   node *head = NULL;
   node *tail=NULL;


   for (int i = 0; i < n; ++i)
   {
   	int num;
   	cin>>num;

   	add_new_node(&head,num,&tail);

   	
   }
   // Part 1
      cout<<"Doubly linked list traversed from front to end: ";

   traverse_from_front_to_end(head);

   cout<<'\n';

   //Part 2

   	cout<<"Doubly linked list traversed from end to front: ";

   traverse_from_end_to_front(tail,NULL);

   cout<<'\n';

   //Part 3
    
   reverse(&head,&tail);

   cout<<"Reversed doubly linked list traversed from front to end: ";


   traverse_from_front_to_end(head);

   cout<<'\n';

   // Part 4

   alternate(&head,&tail);

  cout<<"Alternated doubly linked list traversed from front to end: ";

   traverse_from_front_to_end(head);
   cout<<'\n';






	return 0;
}