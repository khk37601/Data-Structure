#include"TreeNode.h"


int main()
{
	TreeNode * root = CreateTreeNode('A');

	TreeNode * B = CreateTreeNode('B');
    TreeNode * C = CreateTreeNode('C');
    TreeNode * D = CreateTreeNode('D');
    TreeNode * E = CreateTreeNode('E');
    TreeNode * F = CreateTreeNode('F');
    TreeNode * G = CreateTreeNode('G');
	TreeNode * H = CreateTreeNode('H');
    TreeNode * I = CreateTreeNode('I');
    TreeNode * J = CreateTreeNode('J');
	TreeNode * K = CreateTreeNode('K');



	addChildNode(root,B);
	addChildNode(B,C);
    addChildNode(B,D);
    addChildNode(D,E);
    addChildNode(D,F);
    addChildNode(root,G);
    addChildNode(G,H);
	//addChildNode(H,E);
    //addChildNode(H,F);
	addChildNode(root,I);
    addChildNode(I,J);
	addChildNode(J,K);

	print(root,0);
	puts("===========" );


	printNodeAtLevel(root,2);




	return 0;
}