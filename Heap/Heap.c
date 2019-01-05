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

	 //�� �� ���
	 if(h->UsedSize == h->Capacity)
	 {
		 //�ι� �� �Ҵ�
		 h->Capacity *=2;
		 h->node = (Node*)realloc(h->node,sizeof(Node)*h->Capacity);
	 }

	 h->node[currentPosition].data = data;
	 
	 while(currentPosition > 0 && h->node[currentPosition].data < h->node[ParentPosition].data)
	 {
		 //�ڽĳ�庸�� �θ� ��尡 Ŭ��� 
		 Heap_SwapNodes(h,currentPosition,ParentPosition);
		 
		 /* �ٲ��� �ε��� ��ȯ*/
		 currentPosition = ParentPosition;
		 ParentPosition  = Heap_GetParent(currentPosition); 

	 }

	 h->UsedSize++;

}

void Heap_SwapNodes(Heap * h,int index, int index2)
{

	 int CopySize = sizeof(Node);
	 Node * tmp = (Node*)malloc(sizeof(CopySize));

	 /* ��ȯ */
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

	//root�� node[0] ����
	memcpy(root,&h->node[0],sizeof(Node));
	//node[0]�� 0���� �ʱ�ȭ
	memset(&h->node[0],0,sizeof(Node));

	h->UsedSize--;
	Heap_SwapNodes(h,0,h->UsedSize);

	//root�� ���� �ڽ� ��� ��ȯ
	LeftPosition  = Heap_GetLeftChild(0);
	//Leftchild �� 1����� ������ �ڽ��̴�.
	RightPosition = LeftPosition+1;

	//�� �Ӽ����� Ȯ��
	while(1)
	{
		int SelectedChild = 0;

	
		if(LeftPosition >= h->UsedSize)
		{
			//����
			break;
		}
		if(RightPosition >= h->UsedSize)
		{
			SelectedChild = LeftPosition;
		}
		else
		{    
			//left ��� ���� right �� ���� Ŭ ���
			if(h->node[LeftPosition].data > h->node[RightPosition].data)
				
			     SelectedChild = RightPosition;
			else
				SelectedChild = LeftPosition;
		}


		//�θ� ��尡 Ŭ���
		if(h->node[SelectedChild].data < h->node[ParentPosition].data)
		{
			//��ȯ
			Heap_SwapNodes(h,ParentPosition,SelectedChild);
			ParentPosition = SelectedChild;
		}else
			break;

		
		LeftPosition  = Heap_GetLeftChild(ParentPosition);
		RightPosition = LeftPosition+1;

	}

	//�پ�� ũ�� ��ŭ ũ�� ���Ҵ�
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
	//�θ� ��� �ε��� ��ȯ
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