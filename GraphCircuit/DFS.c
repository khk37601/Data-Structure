#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define TRUE  1
#define FALSE 0

typedef struct graphNode
{
	int vertex;
	struct graphNode * next;

}GraphNode;

typedef struct graph
{
	int n; // 정점 개수
	GraphNode *nodes[MAX];
	int visited[MAX];

}Graph;


typedef struct _stack
{
   int data;
   struct _stack * next;

}Stack;

Stack *Top;

int isEmpty()
{
  return Top == NULL;
}

void push(int data)
{
	Stack * stack =(Stack*)malloc(sizeof(Stack));
	stack->data = data;
	stack->next = NULL;
    Top = stack;
}

int pop()
{

	Stack* tmp = Top;
	
	if(isEmpty())
	{
		printf("\n\n 빽");
		return 0;
	}else
	{
		 Top = tmp->next;
		 return tmp->data;
	}

}



void CreateGraph(Graph *g)
{
	int i;
	g->n = 0;
	for(i=0;i<MAX;i++)
	{
		g->nodes[i] = NULL;
		g->visited[i] = FALSE;
	}

}

void insertVectex(Graph *g,int v)
{
	if(((g->n)+1)>=MAX)
	{
		printf("없는 정점입니다.\n");
		return ;
	}

	g->n++;
}

void insertEdge(Graph *g, int u, int v)
{
	
	GraphNode * node;

	if(u >= g->n   || v >= g->n )
	{
		printf("없는 정점입니다.\n");
		return ;
	}

	node =(GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->next   =g->nodes[u];
	g->nodes[u] = node;

}

void print(Graph *g)
{
	int i;
	GraphNode * p;
	for(i=0;i<g->n;i++)
	{
		printf("\n\n\t정점 %c의 인접리스트",i+65);
		p = g->nodes[i];
		while(p)
		{
			printf("-> %c",p->vertex+65);
			p=p->next;
		}
	}
}


void DFS_adjList(Graph *g, int v)
{
	GraphNode *p;
	Top = NULL;
	push(v);
	g->visited[v]= TRUE;
	printf("%c ",v+65);

	while(!isEmpty())
	{
		p = g->nodes[v];

		while(p)
		{
			if(!g->visited[p->vertex])
			{
				push(p->vertex);
				g->visited[p->vertex] =TRUE;
				printf("%c ",p->vertex+65);
				v = p->vertex;
				p = g->nodes[v];
			}else
				p = p->next; 
		}
		// 현재 정점에서 순회할 인접 정점이 더 없는 경우 pop
		v = pop();
	}
}



int main()
{

	int i;
	Graph *g= (Graph*)malloc(sizeof(Graph));
	CreateGraph(g);
	for(i=0;i<7;i++)
		insertVectex(g,i);

	insertEdge(g,0,2);
	insertEdge(g,0,1);
	insertEdge(g,1,4);
    insertEdge(g,1,3);
	insertEdge(g,1,0);
    insertEdge(g,2,4);
    insertEdge(g,2,0);
	insertEdge(g,3,6);
	insertEdge(g,3,1);
	insertEdge(g,4,6);
    insertEdge(g,4,2);
 	insertEdge(g,4,1);
 	insertEdge(g,5,6);
	insertEdge(g,6,5);
	insertEdge(g,6,4);
	insertEdge(g,6,3);
    printf("\nG의 인접 리스트");
	print(g);

	printf("\n\n\n//////////////////\n\n깊이우선 : ");
	DFS_adjList(g,0);

	return 0;
}





