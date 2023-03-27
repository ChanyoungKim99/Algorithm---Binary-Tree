#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	mpRoot = CreateNode(0);
}

Node* BinarySearchTree::CreateNode(int data)
{
	return new Node(data, nullptr, nullptr);
}

Node* BinarySearchTree::Insert(Node* pParent, int data)
{
	if (pParent == nullptr)
	{
		return CreateNode(data);
	}

	if (data < pParent->mData)		// 작으면 왼쪽
	{
		pParent->mLeft = Insert(pParent->mLeft, data);
	}
	else if (data > pParent->mData)	// 크면 오른족
	{
		pParent->mRight = Insert(pParent->mRight, data);
	}

	return pParent;
}

void BinarySearchTree::InOrder(Node* node)
{
	// base case
	if (node == nullptr)
	{
		return;
	}

	// recursive case
	InOrder(node->mLeft);
	Visit(node);
	InOrder(node->mRight);
}
