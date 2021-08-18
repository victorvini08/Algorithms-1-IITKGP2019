#include <iostream>
#include <fstream>

using namespace std;

typedef struct _hashing {
int key;
int value;
struct _hashing *next;
} hash_table;

int hash_function(int val,int size)
{
	return val%size;
}

struct hash_map
{
	hash_table *array;
};


int main()
{
	ifstream input_file;
	ofstream output_file;
	input_file.open("input.txt");
	output_file.open("output.txt");

	int size;
	input_file>>size;
	int t;
	input_file>>t;

    hash_table *table_portfolios = new hash_table[size];
    hash_table *table_counterparties = new hash_table[size];

    for (int i = 0; i < size; ++i)
    {
    	/* code */
    	table_counterparties[i].key = -1;
    	table_counterparties[i].next = NULL;
    	table_portfolios[i].key = -1;
    	table_portfolios[i].next = NULL;
    }
 
	while(t--)
	{
		char sign;
		input_file>>sign;

		if(sign=='+')
		{
			int y,p;
			input_file>>y>>p;
			
            // FOR TABLE HAVING KEYS AS PORTFOLIOS
            int pos = hash_function(p,size);
           
            if(table_portfolios[pos].key==-1)
            {
            	table_portfolios[pos].key =-2;
            	hash_table *temp = new hash_table;
            	temp->key = p;
            	temp->value = y;
            	temp->next = NULL;
            	table_portfolios[pos].next = temp;
            }
            else
            {
                 hash_table *temp = table_portfolios[pos].next;	
                 while((temp->next)!=NULL)
                 {
                 	temp = temp->next;
                 }
                 hash_table *temp2 = new hash_table;
                 temp2->key = p;
                 temp2->value = y;
                 temp2->next = NULL;
                 temp->next = temp2;
            }

             // FOR TABLE HAVING KEYS AS COUNTERPARTIES

            int pos2 = hash_function(y,size);


            if(table_counterparties[pos2].key==-1)
            {
            	table_counterparties[pos2].key =-2;
            	hash_table *temp = new hash_table;
            	temp->key = y;
            	temp->value = p;
            	temp->next = NULL;
            	table_counterparties[pos2].next = temp;
            }
            else
            {
                 hash_table *temp = table_counterparties[pos2].next;	
                 while((temp->next)!=NULL)
                 {
                 	temp = temp->next;
                 }
                 hash_table *temp2 = new hash_table;
                 temp2->key = y;
                 temp2->value = p;
                 temp2->next = NULL;
                 temp->next = temp2;
            }

		}
		else if(sign=='-')
		{
			int y;
			input_file>>y;

			//DELETING IN TABLE HAVING KEYS AS COUNTERPARTIES

			int pos = hash_function(y,size);

		// 	int count = 0;
		// 	int ports[size];

		// 	hash_table *t = table_counterparties[pos].next;
            

		// 	hash_table *prev = NULL;

		// 	if(t->key==y)
		// 	{
		// 		cout<<"WEF"<<endl;
		// 		while(t!=NULL)
		// 		{	if(t->key==y)
		// 		{				
  //                    t = t->next;
  //                    if(t==NULL)
  //                    {
  //                    table_counterparties[pos].next =NULL;
  //                    break;
  //                }
  //            }
		// 		}
		// 	}
			
          
		 }
	}
	
	for (int i = 0; i < size; ++i)
	{
		/* code */
		
		if(table_portfolios[i].key==-1)
		{
			cout<<'p'<<" "<<i<<" "<<-1<<" "<<-1<<endl;
		}
		else
		{
			hash_table *temp = table_portfolios[i].next;
			while(temp!=NULL)
			{
				cout<<'p'<<" "<<i<<" "<<temp->key<<" "<<temp->value<<endl;
				temp = temp->next;
			}
		}

	}

	for (int i = 0; i < size; ++i)
	{
		/* code */
		
		if(table_counterparties[i].key==-1)
		{
			cout<<'c'<<" "<<i<<" "<<-1<<" "<<-1<<endl;
		}
		else
		{
			hash_table *temp = table_counterparties[i].next;
			while(temp!=NULL)
			{
				cout<<'c'<<" "<<i<<" "<<temp->key<<" "<<temp->value<<endl;
				temp = temp->next;
			}
		}

	}

     return 0;

}