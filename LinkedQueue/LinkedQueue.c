#include"LinkedQueue.h"
#include<stdlib.h>

//링크드 큐는 포화 상태를 확인 할 필요가 없다.

/*
  Front                  Gear
   ^                      ^
  ----      ----        ----
  | 1 |  -> | 2 |   ->  | 3 |
  ----      ----        ----
  
  Gear로 추가  Front로 출력
*/

void CreateLinkedQueue(LikedQueue ** queue)
{
	(*queue)->count = 0;
	(*queue)->Front = NULL;
	(*queue)->Rear  = NULL;
}

Node *CreateNode(char * data)
{
	Node * newNode =(Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data =data;
}


void Enqueue(LikedQueue * queue, Node * newNode)
{

	if(queue->Rear == NULL && queue->Rear == NULL)
	{
		queue->Rear  = newNode;
		queue->Front = newNode;
		queue->count++;
	}
	else
	{
		queue->Rear->next = newNode;
		queue->Rear = newNode;
		queue->count++;
	}

}
Node * Dequeue(LikedQueue * queue)
{
	 Node * cur = queue->Front;
	
	 if(queue->Front->next == NULL)
	 {
		 queue->Front = NULL;
		 queue->Rear  = NULL;
	 }
	 else
	 {
		 queue->Front = queue->Front->next;	 

	 }

	 queue->count--;

     return cur;

}
