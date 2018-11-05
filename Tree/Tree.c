#include"TreeNode.h"
#include<stdlib.h>

TreeNode * CreateTreeNode(item data)
{
	TreeNode * newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->Leftchild = NULL;
	newNode->Rightsibing = NULL;
	newNode->data = data;

	return newNode;
}

void addChildNode(TreeNode * ParentNode, TreeNode * ChildNode)
{

	if(ParentNode->Leftchild == NULL)
	{
	  ParentNode->Leftchild = ChildNode;
	}
	else
	{
	  //원래 노드이동 막기 위함
	  TreeNode * tmp = ParentNode->Leftchild;
	 
	  while(tmp->Rightsibing !=NULL)
	    tmp = tmp->Rightsibing;
	  

	   tmp->Rightsibing =  ChildNode;

	}
	
}

void print(TreeNode *tree,int Dept)
{
	int i;
	for(i=0;i<Dept;i++)
	   printf(" ");

	printf("%c [%p] [%p] child[%p]\n",tree->data,tree,tree->Rightsibing,tree->Leftchild);
	
	if(tree->Leftchild !=NULL)
		print(tree->Leftchild,Dept+1);	

	if(tree->Rightsibing != NULL)
		print(tree->Rightsibing,Dept);
}

void printNodeAtLevel(TreeNode * tree,int Level)
{
		int i=0;
	TreeNode * tmp = tree;
	TreeNode * checkSChild =NULL;

	for(i=0;i<Level;i++)
	{  
	   if(tmp->Leftchild != NULL)
	   {
		  checkSChild = tmp;
		  tmp = tmp->Leftchild;
	    }
	    
	}

	while(tmp != NULL && checkSChild->Leftchild !=NULL)
	{
		printf("%c ",tmp->data);
		tmp = tmp->Rightsibing;
	}
	 

	//이전 레벨의 형제노드에 자식 이 있는 지 확인
    while(checkSChild != NULL)
	{
      checkSChild = checkSChild->Rightsibing;
	  if(checkSChild->Leftchild != NULL)
	  {
		  printf("%c ",checkSChild->Leftchild->data);  
	  }

	}
	



}


/*
	 for(i=0;i<Level;i++)
	{
		if(tmp->Leftchild == NULL)
		{
			while(tmp->Rightsibing->Leftchild != NULL)
			{
				tmp = tmp->Rightsibing;
		   
			  if(tmp->Leftchild != NULL)
		          tmp = tmp->Leftchild;
			}

		}else tmp = tmp->Leftchild;
	}

	 while(tmp != NULL)
	 {
		 printf("%c ",tmp->data);
		 tmp = tmp->Rightsibing;
	 }

	  if(tmp->Leftchild != NULL)
		{	
		   tmp = tmp->Leftchild;
		   while(tmp != NULL)
		   {
			   printf("%c ",tmp->data);
			   tmp=tmp->Rightsibing;
		   }
		
		
		}
		else
		{


		}



		=[=====================================

	


	*/