#include <iostream>
using namespace std; 

struct node
{
	int data;
	struct node *next;
};

void insertnodebefore(node** head,int value)
{
	node* n = (node*)malloc(sizeof(node));
	n->data = value;
	n->next = *(head) ;
	*head = n ; 
}

void printlist(node *head)
{
	while ( head != NULL )
	{
		cout << head->data ; 
		head = head->next ;
	}
}

int main()
{
	node **list = NULL ;
	insertnodebefore(list,10);
	insertnodebefore(list,12);
	insertnodebefore(list,14);
	printlist(*list);
	return 0;
}