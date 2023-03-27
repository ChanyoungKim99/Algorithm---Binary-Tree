#pragma once
#include <iostream>

struct Node
{
	int mData;
	Node* mLeft;
	Node* mRight;

	Node(int data, Node* left, Node* right)
	{
		mData = data;
		mLeft = left;
		mRight = right;
	}
};

class BinarySearchTree
{
	Node* mpRoot;

public:
	BinarySearchTree();
	Node* CreateNode(int data);
	Node* Insert(Node* pParent, int data);
	void InOrder(Node* node);

	inline void Visit(Node* node) const
	{
		std::cout << node->mData << std::endl;
	}

	inline Node* GetRoot() const
	{
		return mpRoot;
	}
};

