#include"CricleQueue.h"

void CreateQueue(CircleQueue ** queue,int cap)
{
             	
	*queue  =(CircleQueue*)malloc(sizeof(CircleQueue)); 
	(*queue) -> Capacity = cap;
	(*queue) -> Front    = 0;
	(*queue) -> Rear     = 0;

	/* 더미 노드를 통해서 선형큐가 포화 상태인지 아닌지를 알수 있기에 Capacity 보다 +1 더 공간을 만든다.*/
	(*queue) -> Nodes    = (Node*)malloc(sizeof(Node)* (cap+1));// 포화상태인지 구분할 더미 노드를 위함 
 
}

void Enqueue(CircleQueue * queue, data item)
{
	//노드배열에 접근할 인덱스
	int position = 0;
	
	/*
	   Queue에 삽입 하기 위해서는 
	   1) 우선  큐가 포화상태인지를 확인한다.
	   2) 포화상태가 아니면 Rear가 더미노드에 도달 했는지를 확인
	   3) Rear가 더미 노드에 아직 도달 하지 않을 경우
	*/
	
	if(IsFull(queue))
	{
		printf("포화 상태입니다.");
		return;
	}
	// 더미노드에 도달 했을 경우 다시 회귀
	if(queue->Rear == queue->Capacity+1)
	{
		queue->Rear = 0;
		position    = 0;
	}
	else
	{
		//아닐 경우 Rear를 1씩증가
		position = queue->Rear++;

	}
	
	// 인덱스를 통해 노드접근 후 데이터 삽입
	queue->Nodes[position].Element = item;
}


data Dequeue(CircleQueue * queue)
{
	
	//현재 인덱스를 저장
	int position = queue->Front;
    // 더미 노드에 도달 할경우 다시 회귀	
	if(queue->Front == queue->Capacity)
	{
		queue->Front = 0;
	}
	else
	{
		//인덱스 1씩 증가
		queue->Front++;
	}
	return queue->Nodes[position].Element;

}

int IsFull(CircleQueue *queue)
{
	/*
	    두가지 경우를 생각 해봐야 한다.
		1) Front가 Rear 앞에 있을경우
		2) Front가 Rear 뒤에 있을경우

		1)    Front            Rear
	        --------------------------
	        |  1    |  2   |         |
		    --------------------------
	          [0]      [1]     [2]
 
           가득 찼는지를 어떻게 알까? ...
		   초기에 큐의 크기를 설정 하였다... 당연히 Capactiy 값과 같은지를 확인 하면 된다.
		   또.. 어떻게 알아 내야 하는 걸까? 우리는 Rear와 Front를 움직여서 확인 하지 못한다.
		   Rear와 Front를 굳이 움직여서 알아볼 필요는 없다 Rear와 Front를 이용 하면 된다.
		   첫번째 경우를 다시 떨올려 보자
		   Front가 Rear 앞에 있을 경우 이다. 그러면 Fornt값은 Rear 보다 작을 수 밖에 없다.
		   (Rear - Front)를 하면 우리가 사용하고 있는 크기를 알아낼 수 있다.
		   (Rear - Front)값이 Capactiy와 같은면  포화 상태 인것이다.




		   2)         Rear
   	      	          Front           
	        --------------------------
	        |    3   |  2   |         |
		    --------------------------
	          [0]      [1]     [2]

               


			Rear의 값으로 노드가 가득찼는지 아닌지를 그냥 하면 안될까? 당연히 안된다.


	*/


	if(queue->Front < queue->Rear)
	{
		return (queue->Rear - queue->Front) == queue->Capacity;
	}else
	{
		return (queue->Rear + queue->Front )  == queue->Capacity;
	}
}

int GetSize(CircleQueue * queue)
{
	//Front와 Rear가 같을경우와 Front보다 Rear가 앞에 있을 경우 
	if(queue->Front <= queue->Rear)
	{
		return (queue->Rear - queue->Front);
	}else
		return  queue->Capacity - queue->Rear-1;


}
int IsEmty(CircleQueue * queue)
{
	// Rear 와 Front 같은 경우
	if(queue->Rear == queue->Front)
		return  1;
	else
		return 0;
}

void Destroy(CircleQueue * queue)
{
	free(queue->Nodes);
	free(queue);

}