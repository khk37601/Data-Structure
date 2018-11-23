# implement-of-C-DataStructure
혼자서 C언어 자료구조를 공부하는 공간입니다.
------------------------------------------------
## LinkedList  why use Double Pointer ?
```
이중포인터 사용 이유 ?

결국은 주소 문제 때문에 사용한다.

단일 포인터를 쓸경우 문제점을 보여 주는 예시이다.
i)
  List           haed           NewNode
---------       ------          -------
  NULL  |      | 0x01 |         | 117 |          *head 값은 NULL이다.
---------       ------          -------
  0X01           0x02            0x03 

head의 값이 NULL 이면 NewNode를 가르킨다.

if(head == NULL)
  head = NewNode;

  List           haed           NewNode
---------       ------          -------
  NULL  |      | 0x03 |------>  | 117 |       
---------       ------          -------
  0X01           0x02            0x03 

함수를 벗어 나면서 변수값은다  메모리를 반납 한다. 
문제 없이 진행 하는것처럼 보인다.

ii)

else
{
      Node *tail = head;
      while(tail != NULL)
      {
          tail = tail -> next;
      }

       tail->next =newNode;
 
}

우리가 원하는 형태 모습이다.
                                  tail
  List           haed           frist_Node     NewNode
---------       ------          -------        ------
  NULL  |      | 0x03 |------>  | 117 |   ---> | 118 |
---------       ------          -------        ------
  0X01           0x02            0x03           0x04


하지만 우리가 원하는 것처럼 연결을 못하는 것뿐만 아니라 
head 노드를 접근 조차 할 수 없다.
그이유는 아직 head는 즉 List가 가지고 있는 주소값은 여전히 NULL 이기떄문이다.
그래서 우리가 이중포인터를 써야 하는이유 이다 List즉 head가 가지고 있는 주소를
바뀌기 위해서다.

append_node(Node **head , Node*newNode)
 
  if(*head == NULL)
  {
     *head = newNode;
  }

 *head : head를 통해서 역참조를 통해서 List가 가지고 있는 주소값을 NewNode의 
  주소값으로 변경 시켜 주는것이다.
  이렇게 하면 우리가 원하는 싱글리스트를 구현 할 수 있다.

                                  tail
  List           haed           frist_Node     NewNode
---------       ------          -------        ------
  0x03  |      | 0x03 |------>  | 117 |   ---> | 118 |
---------       ------          -------        ------
  0X01 |         0x02            0x03           0x04
       |                          ^ 
       ---------------------------|
```

 
 
 
