#include<stdio.h>
#include<stdlib.h>

/*
  Heap은 링크드 리스트보다 배열로 구현 하는것이 좋다.
  LinkedList 로 최 우측 하단 노드를 어떻게 찾는 가? 라는
  효율적인 방법이 어렵다.
*/

typedef int Data;

/* heap 노드 */
typedef struct HeapNode
{
	Data data;

}Node;

/* 힙 구조체 틀*/

typedef struct heap
{
	Node * node;
	int Capacity; // 힙 크기
	int UsedSize; //  사용 수


}Heap;


Heap * Heap_Create(int Capacity);
void   Heap_Destroy(Heap * h);
void   Heap_Insert(Heap *h, Data data);
void   Heap_DeleteMin(Heap *h , Node * root);
int    Heap_GetParent(int index);
int    Heap_GetLeftChild(Heap * h,int index, int index2);
void   Heap_SwapNodes(Heap * h,int index, int index2);
void   Heap_PrintNodes(Heap *h);