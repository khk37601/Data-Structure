#include"CricleQueue.h"


int main()
{
	CircleQueue * Queue;
	int i;
	CreateQueue(&Queue,5);

	Enqueue(Queue,1);
	Enqueue(Queue,2);
	Enqueue(Queue,3);
	Enqueue(Queue,4);
	Enqueue(Queue,5);

    
	
	printf("size : %d \n",GetSize(Queue));
	printf("\n full ? %d\n",IsFull(Queue));

	for(i=0;i<3;i++)
	  printf("%d\n",Dequeue(Queue));
	 puts(" "); 

    printf("size : %d \n",GetSize(Queue));
    printf("full ? %d\n",IsFull(Queue));

	Enqueue(Queue,7);
   	Enqueue(Queue,8);
    Enqueue(Queue,9);
    Enqueue(Queue,10);
    Enqueue(Queue,11);
 
	 printf("size : %d \n",GetSize(Queue));
	   printf("full ? %d\n",IsFull(Queue));

	for(i=0;i<GetSize(Queue)+1;i++)
	  printf("%d\n",Dequeue(Queue));
	    
    

  printf("size : %d \n",GetSize(Queue));
  printf("\n full ? %d\n",IsFull(Queue));


  Destroy(Queue);

}