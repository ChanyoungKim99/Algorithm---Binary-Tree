//#include "BinaryTree.h"
#include "BinarySearchTree.h"

int main()
{
	//BinaryTree myTree;
	//auto pRoot = myTree.GetRoot();
	//pRoot->mData = 1;

	//myTree.InsertLeft(pRoot, 2);
	//myTree.InsertRight(pRoot, 3);

	//myTree.InsertLeft(pRoot->mLeft, 4);
	//myTree.InsertRight(pRoot->mLeft, 5);
	//myTree.InsertLeft(pRoot->mRight, 6);
	//myTree.InsertRight(pRoot->mRight, 7);

	//// Traverse(순회) 하면서 출력하기
	//myTree.BreadthFirst();
	//std::cout << std::endl;

	//myTree.DepthFirst();
	//std::cout << std::endl;

	//myTree.DepthFirstRecursive(pRoot);
	//std::cout << std::endl;

	//std::cout << myTree.Sum(pRoot) << std::endl;

	//std::cout << myTree.Search(pRoot, 5) << std::endl;
	//std::cout << myTree.Search(pRoot, 9) << std::endl;



	BinarySearchTree myTree;
	
	auto pRoot = myTree.Insert(nullptr, 8);
	myTree.Insert(pRoot, 3);
	myTree.Insert(pRoot, 10);
	myTree.Insert(pRoot, 1);
	myTree.Insert(pRoot, 6);

	myTree.InOrder(pRoot);
	std::cout << std::endl;
}