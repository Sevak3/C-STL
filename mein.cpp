#include <iostream>
#include "BinarTree.h"

int main()
{
	BinarTree<int> tree;

	tree.insert(9);
	tree.insert(11);
	tree.insert(1);
	tree.insert(5);
	tree.insert(3);
	tree.insert(17);
	tree.insert(4);
	tree.insert(13);
	tree.insert(15);
	tree.insert(14);
	// tree.insert(12);

	 /*std::cout << tree.min()->m_value << std::endl;
	 std::cout << tree.max()->m_value << std::endl;*/

	 /*std::cout << tree.successor(tree.getRoot(), 5)->m_value << std::endl;
	 std::cout << tree.predecessor(tree.getRoot(), 3)->m_value << std::endl;*/

	 /*tree.inorder(tree.getRoot());
	 tree.postorder(tree.getRoot());
	 tree.preorder(tree.getRoot());*/

	// tree.bfsTravers();

	/*tree.inorder(tree.getRoot()); std::cout << std::endl;
	tree.deleteNode(tree.getRoot(), 13);
	tree.inorder(tree.getRoot());*/

	/*auto getroot = tree.getRoot();
	std::cout << tree.predecessor(getroot)->m_value << std::endl;*/

	 //std::cout << tree.maxDepth() << std::endl;

	/*int n;
	std::cin >> n;
	std::cout << tree.find(n)->m_value << std::endl;*/

	//std::cout << tree.maxDepth() << std::endl;

	//std::cout << tree.maxDepth() << std::endl;

	system("pause");
	return 0;
}