#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 30

typedef struct graphnode
{
	int vertex; // ���� �� ��Ÿ��
	struct graphnode* next;
}GraphNode;

typedef struct graph
{
	int n;    //�׷��� ���� ����
	GraphNode * arr[MAX_VERTEX];//�׷��� ������ ����  ��� ������ �迭
}Graph;

void CreateGraph(Graph *g)
{
    int i;
	g->n = 0;
	for(i=0;i<MAX_VERTEX;i++)
		g->arr[i]= NULL;
}

void InsertVertex(Graph *g , int v)
{
	if(((g->n)+1)>MAX_VERTEX)
	{
		printf("�ʰ� �Ͽ����ϴ�.");
		return;
	}
	g->n++;
}

void InsertEdge(Graph * g, int u, int v)
{
	GraphNode * newEdge = NULL;	
	if(v>=((g->n)+1) && u>=((g->n)+1))
	{
		printf("�׷����� ���� �����Դϴ�.");
		return;
	}

	newEdge =  (GraphNode*)malloc(sizeof(GraphNode));
	newEdge->vertex = v;
	newEdge->next = g->arr[u];
	g->arr[u] = newEdge;
 
}


void print(Graph *g)
{

	int i;
	GraphNode *p = NULL;
	for(i=0;i<g->n;i++)
	{
		printf("\n\t\t���� %c�� ���� ����Ʈ",i+65);
		p=g->arr[i];
		while(p)
		{
		  printf("->");
		  printf("%c",(p->vertex)+65);
		  p=p->next;
		}
	}

}




int main()
{
	Graph * g;
	int i;
	g = (Graph*)malloc(sizeof(Graph));
	CreateGraph(g);
	
	for(i=0;i<4;i++)
		InsertVertex(g,i);

	InsertEdge(g,0,3);
	InsertEdge(g,0,1);
	InsertEdge(g,1,3);
	InsertEdge(g,1,2);
	InsertEdge(g,1,0);
	InsertEdge(g,2,3);
	InsertEdge(g,2,1);
	InsertEdge(g,3,2);
	InsertEdge(g,3,1);
	InsertEdge(g,3,0);

	print(g);  






	return 0;
}