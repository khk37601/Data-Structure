#define __QUEUENODE_H__
#include<stdio.h>
#include<stdlib.h>

typedef int data;

typedef struct _node
{
	data Element;

}Node;

typedef struct cricleQueue
{

	int Capacity; // 용량
    int Front;   // 전단의 인덱스
	int Rear;    // 후단의 인덱스
	Node * Nodes;


}CircleQueue;

//Queue 생성
void CreateQueue(CircleQueue ** queue, int cap);
//삽입
void Enqueue(CircleQueue * queue,data item);
//삭제
data Dequeue(CircleQueue * queue);
//포화유무
int IsFull(CircleQueue *queue);
//현재 사용하는 size 
int GetSize(CircleQueue * queue);
//비워있는지 유무
int IsEmpty(CircleQueue * queue);
void Destroy(CircleQueue * queue);