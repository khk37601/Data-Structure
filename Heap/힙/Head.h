/*
  힙 구현은 LinkedList 보다는 배열로 구현 하는 것이 편하다.
  LinkedList로 구현 하면 힙의 가장 최 우측 노드를 어떻게 찾을 것
  인가? 라는 문제를 효율적인 방법이 없다.

*/
#include<stdio.h>
#include<stdlib.h>
typedef int Data;

/*
   힙 노드 표현
*/
typedef struct HeapNode
{
	Data data;

}Node;

/* 힙 자체 구조체 틀*/
typedef struct Heap
{
	Node * node;  
	int Capacity;  //배열의크기
	int UsedSize;  // 사용 수
}Heap;

