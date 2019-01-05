#include "Heap.h"
#include<string.h>

Heap * Heap_Create(int Capacity)
{
	Heap * NewHeap =(Heap*)malloc(sizeof(Heap)*Capacity);
	NewHeap->Capacity=Capacity;
	NewHeap->UsedSize = 0;
	NewHeap->node = (Node*)malloc(sizeof(Node)*NewHeap->Capacity);
	return NewHeap;

}

void  Heap_Insert(Heap *h, Data data)
{
	 int currentPosition  = h->UsedSize;
	 int ParentPosition   = Heap_GetParent(currentPosition);

	 //꽉 찰 경우
	 if(h->UsedSize == h->Capacity)
	 {
		 //두배 재 할당
		 h->Capacity *=2;
		 h->node = (Node*)realloc(h->node,sizeof(Node)*h->Capacity);
	 }

	 h->node[currentPosition].data = data;
	 
	 while(currentPosition > 0 && h->node[currentPosition].data < h->node[ParentPosition].data)
	 {
		 //자식노드보다 부모 노드가 클경우 
		 Heap_SwapNodes(h,currentPosition,ParentPosition);
		 
		 /* 바꾼후 인덱스 교환*/
		 currentPosition = ParentPosition;
		 ParentPosition  = Heap_GetParent(currentPosition); 

	 }

	 h->UsedSize++;

}

void Heap_SwapNodes(Heap * h,int index, int index2)
{

	 int CopySize = sizeof(Node);
	 Node * tmp = (Node*)malloc(sizeof(CopySize));

	 /* 교환 */
	 memcpy(tmp,&h->node[index],CopySize);
	 memcpy(&h->node[index],&h->node[index2],CopySize);
	 memcpy(&h->node[index2],tmp,CopySize);

	 free(tmp);

}
void Heap_DeleteMin(Heap *h , Node * root)
{
	int ParentPosition = 0;
	int LeftPosition   = 0;
	int RightPosition  = 0;

	//root에 node[0] 복사
	memcpy(root,&h->node[0],sizeof(Node));
	//node[0]에 0으로 초기화
	memset(&h->node[0],0,sizeof(Node));

	h->UsedSize--;
	Heap_SwapNodes(h,0,h->UsedSize);

	//root의 왼쪽 자식 노드 반환
	LeftPosition  = Heap_GetLeftChild(0);
	//Leftchild 에 1더허면 오른쪽 자식이다.
	RightPosition = LeftPosition+1;

	//힙 속성유지 확인
	while(1)
	{
		int SelectedChild = 0;

	
		if(LeftPosition >= h->UsedSize)
		{
			//종료
			break;
		}
		if(RightPosition >= h->UsedSize)
		{
			SelectedChild = LeftPosition;
		}
		else
		{    
			//left 노드 값이 right 값 보다 클 경우
			if(h->node[LeftPosition].data > h->node[RightPosition].data)
				
			     SelectedChild = RightPosition;
			else
				SelectedChild = LeftPosition;
		}


		//부모 노드가 클경우
		if(h->node[SelectedChild].data < h->node[ParentPosition].data)
		{
			//교환
			Heap_SwapNodes(h,ParentPosition,SelectedChild);
			ParentPosition = SelectedChild;
		}else
			break;

		
		LeftPosition  = Heap_GetLeftChild(ParentPosition);
		RightPosition = LeftPosition+1;

	}

	//줄어든 크기 만큼 크기 재할당
	if(h->UsedSize < (h->Capacity/2))
	{
		h->Capacity /=2;
		h->node = (Node*)realloc(h->node,sizeof(Node)*h->Capacity);
	}



}

int Heap_GetLeftChild(int index)
{
	return (int)(2*index)+1;
}


int Heap_GetParent(int index)
{
	//부모 노드 인덱스 반환
	return (int)((index-1)/2);
}
void   Heap_Destroy(Heap * h)
{
	free(h->node);
	free(h);

}
void   Heap_PrintNodes(Heap *h)
{
	int size= h->UsedSize;
	int i=0;
	for(i=0;i<size;i++)
	{
		printf("%d ",h->node[i].data);
	}
	printf("\n");

}