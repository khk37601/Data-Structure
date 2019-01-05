#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 30


typedef struct graphType
{
   int n; //�׷��� ���� ����
   int addjMatrix[MAX_VERTEX][MAX_VERTEX];
}GraphType;


void  CreateGraph(GraphType *g)
{
	int i,j;
	g->n =0;
	/* �׷��� �ʱ�ȭ */
	for(i=0;i<MAX_VERTEX;i++)
	{
		for(j=0;j<MAX_VERTEX;j++)
			g->addjMatrix[i][j]=0;
	}

}
/* ������ ���� ���� */
void insertVertex(GraphType *g,int v)
{
	if(((g->n)+1) > MAX_VERTEX)
	{
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�.");
		return;
	}
	/**/
	g->n++;
}
void insertEdge(GraphType *g , int u, int v)
{
	if(u>=g->n || v>=g->n)
	{
		printf("\n �׷����� ���� �����Դϴ�.");
		return;
	}
    
	g->addjMatrix[u][v]=1;
}

void print_adjMatrix(GraphType *g)
{
	int i,j;
	for(i=0;i<(g->n);i++)
	{
		for(j=0;j<(g->n);j++)
			printf("%d  ",g->addjMatrix[i][j]);
		printf("\n");
	}
}


int main()
{

	int i;
	GraphType *G1,*G2,*G3,*G4;
	G1 =(GraphType*)malloc(sizeof(GraphType));
	G2 =(GraphType*)malloc(sizeof(GraphType));
    G3 =(GraphType*)malloc(sizeof(GraphType));
    G4 =(GraphType*)malloc(sizeof(GraphType));

	CreateGraph(G1);CreateGraph(G2);CreateGraph(G3);CreateGraph(G4);

	for(i=0;i<4;i++)
		insertVertex(G1,i);

	insertEdge(G1,2,3);
	insertEdge(G1,0,1);
	insertEdge(G1,0,2);
	insertEdge(G1,3,1);
	insertEdge(G1,3,0);
	insertEdge(G1,2,2);
	
	print_adjMatrix(G1);



	return 0;
}