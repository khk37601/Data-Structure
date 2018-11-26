#include "Node.h"


/*
  i)
         ------------------
  NULL <-| pre| data| next| ->NULL
         ------------------

*/

//노드생성,노드주소 반환
Node *create_node(item data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next= NULL;
	newNode->pre = NULL;
	newNode ->data =data;
	return newNode;
}
//끝에 노드추가
/*
    i)          head           
	      ------------------
  NULL <-| pre| data| next| ->NULL
          ------------------

   ii)                        move
              head   tail  ----------->   tail                 
               ▽     ▽                   ▽                  
	      ------------------      --------------------  
  NULL <-| pre| data| 0x02 | ->   | 0x01| data | NULL |   .........    
          ------------------ <--  --------------------
		       0x01                       0x02 
			                             newNode

*/
void appned_node(Node ** head,Node * newNode)
{
	  if(*head == NULL)
	  {
		  *head = newNode;

	  }else
	  {
		  Node * tail = *head;	
		  //tail != NULL 에러 발생
		  // tail 이 NULL되고 반복문 종료
		  // tail은 NULL이다.
		  // 그러므로 아래 조건문으로 실행 해야 한다.
		  while(tail->next !=NULL)
		  {
			   tail = tail->next;
		  }		 
		    tail->next = newNode;
			newNode->pre = tail;
	  }

}

void print_revers(Node ** head)
{
	Node * cur = *head;
	//cur를 끝노드로 이동
	while(cur->next !=NULL )
	{
		cur = cur->next;
	}
	  // 역순으로 출력
	 while(cur != NULL)
	 {
		 printf("<- %d ",cur->data);
		 cur =cur->pre;
	 }
	 puts(" ");
}

//노드 출력
void print(Node **head)
{
	 Node * cur = *head;
	 Node * pre = *head;

	 while(cur !=NULL /*&&  pre->next != NULL*/ )
	 {		 
		 printf(" %d ->",cur->data);
		 cur = cur->next;
	}
	   puts(" ");

}
//중간에 노드 추가
void middel_insert(Node **head, Node * newNode,item number)
{
	Node * cur = *head;
	Node * pre = NULL;
	
	int i;
	for(i=0;i<number;i++)
	{
		pre = cur;
		cur = cur->next; 
	}

	// 중간에 노드 삽입 하는 핵심 !!
	 cur->pre = newNode;
	 newNode->next =cur;
	 newNode->pre = pre;
	 pre->next = newNode;
}

Node * find_node(Node **head, item data)
{
	Node * cur = *head;
	Node * node = NULL;

	while(cur != NULL)
	{
		if(cur->data == data)
		{
			node = cur;
		}
		cur= cur->next;
	}

	 return  node;
}


void delete_node(Node ** head, item data)
{
     Node * del = find_node(head,data);
	 Node * fro = del;//삭제노드 앞 노드
	 Node * pre = *head;//삭제노드 이전 노드
	 
	if(del)
	{
	   // 중간 노드일 경우
		/*
		       다음노드가 이전노드와 다음노드가 
			   NULL이 아니여지만 중간에 있는 노드 이다.

		*/
		if(del->next != NULL && del->pre != NULL)
	    {
		  while(pre->next !=del )
		  {
			 pre = pre->next;
		  }
		     fro = fro->next;
            
			 pre->next = fro;
			 fro->pre = pre;
			 free(del);
		}

		// 처음 노드일 경우
		/*
		      삭제노드와 헤드노드가 같은면 처음 노드
			  head가 가르키는 노드가 사리지게 되므로
			  앞의노드로 이동하여 head를 가르키게 하고
			  해당 노드 삭제
		*/
		if(del == pre)
		{
			fro = fro->next;
			fro->pre = NULL;
			*head = fro;
			free(del);
		}
		 // 마지막 노드일 경우
		if(del->next == NULL)
		{
			//del와 같은 노드가 되기전까지만 이동
			while(pre->next !=del)
			{
				pre = pre->next;
			}
			  pre->next = del->next;// pre->next =NULL;
			  free(del);

		}



   }

}

