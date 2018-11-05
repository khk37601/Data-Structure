#include<stdio.h>
#include "Stack_Node.h"

int main()
{
	LinkedListStack * stack= NULL;
	StackNode * newNode = NULL;
	
	create_stack(&stack);

	push(stack,CreateNode("10"));
	push(stack,CreateNode("20"));
    push(stack,CreateNode("30"));


	newNode = pop(stack);
	printf("%s\n",newNode->c);
	destroyNode(newNode);

	printf("%s\n",Top(stack)->c);

	


	return 0;
}