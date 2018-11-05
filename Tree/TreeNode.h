#define __TreeNode_h__
#include<stdio.h>
typedef char item;

typedef struct _node
{
     item data;
	 struct _node * Leftchild;
	 struct _node * Rightsibing;

}TreeNode;

TreeNode * CreateTreeNode(item data);
void addChildNode(TreeNode * Leftchild, TreeNode * Rightsibing);
void print(TreeNode *tree, int Dept);
void printNodeAtLevel(TreeNode * tree,int Level);