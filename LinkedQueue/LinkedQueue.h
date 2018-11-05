/*
   링크드 큐  VS 선형 큐


    링크드 큐의 장점 노드가 가득 차 있는지 확인 할필요가 없다.

  선형 큐)
   1. 크기를 예상 가능경우
   2. 고성능이 필요한 버퍼 경우
  링크드 큐)
   1. 크기를 예상 하지 못할 경우

   속도 
   링크드 큐  <<  선형 큐

*/

#define __LINKEDQUEUE_H__
#include<stdio.h>

typedef struct _node
{
	char * data;
	struct _node * next;

}Node;

typedef struct likedqueue
{
	Node * Rear;
	Node * Front;
    int count;
}LikedQueue;

void Enqueue(LikedQueue * queue, Node * newNode);
Node * CreateNode(char * data);
void CreateLinkedQueue(LikedQueue ** queue);
Node * Dequeue(LikedQueue * queue);