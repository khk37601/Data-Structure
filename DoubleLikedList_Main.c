#include<stdio.h>
#include "Node.h"

int main()
{
	Node * List= NULL;
	Node * newNode = NULL;

	newNode = create_node(10);
	appned_node(&List,newNode);

	newNode = create_node(20);
	appned_node(&List,newNode);

	newNode = create_node(30);
	appned_node(&List,newNode);

	newNode = create_node(40);
	appned_node(&List,newNode);

	print(&List);
    print_revers(&List);

	 newNode = create_node(50);
	 middel_insert(&List,newNode,2);
	 newNode = create_node(70);
	 middel_insert(&List,newNode,4);
	 print(&List);
	 print_revers(&List);
	 
	 delete_node(&List,50);
	 print(&List);
	 print_revers(&List);
	 
	 delete_node(&List,10);
	 print(&List);
	 print_revers(&List);


	return 0;
}