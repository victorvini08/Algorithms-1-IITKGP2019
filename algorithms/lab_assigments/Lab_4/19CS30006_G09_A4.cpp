#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

struct Node {
	char symbol ;
	int frequency ;
	Node * next ;
	Node * left ;
	Node * right ;
};



void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    cout << node->symbol << " "<<node->frequency<<","; 

    printPreorder(node->left);  
  
    printPreorder(node->right); 
}  

 Node* create_node(int freq,char letter)
{
	Node* new_node = new Node;
    
    new_node->symbol= letter;
    new_node->frequency= freq;
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->next=NULL;
}

int find_minimum(Node* array[],int value,int length)
{
   int mini=10000;
   int min_pos=10000;
   for (int i = 0; i < length; ++i)
   {
   	/* code */
       if(array[i]->frequency<mini && i!=value)
       {
       	mini=array[i]->frequency;
       	min_pos=i;
       }
       else if(array[i]->frequency==mini && i!=value)
       {
       	  if(array[i]->symbol!='N')
       	  {
              if(i<min_pos)
              {
              	min_pos=i;
              }
       	  }
       }

   }
   return min_pos;
}

Node* make_huffman_tree(int complete_frequency_array[])
{

     Node* array[2000];
	for (int i = 0; i < 36; ++i)
	{
		/* code */
		if(i<26)
		{
			char c;
			c=(char)('a'+i);
			
		Node* temp=create_node(complete_frequency_array[i],c);
		array[i]=temp;
	    }
	    else
	    {
	    	char c;
			c=(char)('0'+i-26);
	    	Node* temp=create_node(complete_frequency_array[i],c);
	    	array[i]=temp;
	    }
	}
	 int total_nodes_left=36;
     int length=36;
	while(total_nodes_left>1)
	{
       int left= find_minimum(array,-100,length);  
       int right= find_minimum(array,left,length);

       Node* temp_left= array[left];
       Node* temp_right= array[right];

       Node* top= new Node;
       top->left=temp_left;
       top->right=temp_right;
       top->frequency= temp_left->frequency+temp_right->frequency;
       top->next=NULL;
       char cc;
        
       cc=char('N'+length-35);
       top->symbol= cc;
       array[length]=top;
       length++;
       total_nodes_left--;
	}
	return array[find_minimum(array,-1,length)];
}

int main()
{
    FILE *f;
    FILE *output_file;

    output_file=fopen("output.txt","w");


    f=fopen("log.txt","r");
    char line[1000];
    int flag=0;
    int frequency_chars[26]={0};
    int frequency_nums[10]={0};
    int n;
    char number[100];
    fgets(number,sizeof(number),f);
   
    while (fgets(line, sizeof(line), f)) {
      
       for (int i = 0; i < strlen(line); ++i)
         {
         	/* code */
         	
         	if(line[i]>=48 && line[i]<=57)
         	{
         		frequency_nums[line[i]-'0']++;
         	}
         	else if(line[i]>=97 && line[i]<=122)
         	{
         		frequency_chars[line[i]-'a']++;
         	}

         }  
    }
    int complete_frequency_array[36];
    int count=0;
     for (int i = 0; i < 26; ++i)
     {
     	/* code */
     	complete_frequency_array[count]=frequency_chars[i];
     	count++;
     	fprintf(output_file, "%c=%d,",char('a'+i),frequency_chars[i] );
     }
     for (int i = 0; i < 10; ++i)
     {
     	/* code */
     	complete_frequency_array[count]=frequency_nums[i];
     		count++;
     	if(i!=9)
     	{     		

     	fprintf(output_file, "%c=%d,",char('0'+i),frequency_nums[i] );
     }
     else
     {
     	fprintf(output_file, "%c=%d",char('0'+i),frequency_nums[i] );
     }
     }

    
     Node* root = make_huffman_tree(complete_frequency_array);     

     //printPreorder(root);
   
    fclose(f);

	return 0;
}