#include<stdio.h>
#include<stdlib.h>
#define item int
/*

     ------------------
     | pre| data| next|
     ------------------
	 DoubleLinkedList
	 두개의 포인터를 가지고 있는 형태다
      
	  why? 
	   
      단일연결리스트는 단방향으로 노드를 순방 하게 된다.
	  역뱡항으로 노드를 출력 할 수 없고, 중간의 노드를 다시 찾고 
	  싶다면 다시 처음 부터 검색 하는 기회 비용을 가지고 있다.
	  이러한 문제를 해결 하기 위해서 이중연결 리스트를 사용 하는것이다.


*/
//이중 링크리스트 
typedef struct _node
{
    item data;
	struct _node * next; // 앞의노드를
	struct _node * pre;  // 이전 노드를

}Node;

//노드 생성
Node * create_node(item data);
//끝에노드 추가
void appned_node(Node**head,Node * newNode);
//정방향 출력
void print(Node **head);
//노드 중간에 삽입
void middel_insert(Node**head, Node*newNode,item number);
//노드 삭제
void delete_node(Node **head, item data);
//노드 찾기
Node * find_Node(Node **head, item data);
//역방향 출력
void print_revers(Node **head);
