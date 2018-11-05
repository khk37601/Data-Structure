#define __BINARYTREENODE_H__
#include<stdio.h>
typedef char item;

typedef struct _treeNode
{

	item data;
	struct _treeNode * right;
	struct _treeNode * left;

}BinaryTreeNode;

BinaryTreeNode * CreateNode(item data);
void PreorderPrintTree(BinaryTreeNode * tree);
void InorderPrintTree(BinaryTreeNode * tree);
void PostderPrintTree(BinaryTreeNode * tree);
void DestroyTree(BinaryTreeNode * tree);
void DestroyNode(BinaryTreeNode * tree);