#include"BinaryTreeNode.h"

int main()
{

	BinaryTreeNode * root = CreateNode('A');
	BinaryTreeNode * B = CreateNode('B');
    BinaryTreeNode * C = CreateNode('C');
    BinaryTreeNode * D = CreateNode('D');
    BinaryTreeNode * E = CreateNode('E');
	BinaryTreeNode * F = CreateNode('F');
    BinaryTreeNode * G = CreateNode('G');


	root -> left  = B;
	B    -> left  = C;
	B    -> right = D;
	root -> right = E;
	E    -> left  = F;
	E    -> right = G;

	puts("===========================전위=========");
	PreorderPrintTree(root);
	puts("============중위========================");
	InorderPrintTree(root);
	puts("============후위========================");
	PostderPrintTree(root);


	DestroyTree(root);


	return 0;
}