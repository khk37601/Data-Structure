#include "Heap.h"

int main()
{
	Heap * h = 	Heap_Create(5);
	Node  minNode ;

	Heap_Insert(h,12);
	Heap_Insert(h,87);
	Heap_Insert(h,111);
	Heap_Insert(h,34);
    Heap_Insert(h,16);
	Heap_Insert(h,16);
	Heap_Insert(h,75);
	Heap_PrintNodes(h);

	Heap_DeleteMin(h,&minNode);
	Heap_PrintNodes(h);


	return 0;
}
