#pragma once
#include <iostream>


// POD 
struct Node					// struct = ��� ����� public�� class
{
	int mData;

	// �ڱ� ����
	Node* mLeft;
	Node* mRight;

	// ������
	Node(int data, Node* left, Node* right) :
		mData{ data }, mLeft{ left }, mRight{right}
	{
	}
};

class BinaryTree
{
private:
	Node* mpRoot;			// root�� �ȴٸ�, ��� ��������
	
public:
	BinaryTree();			// �ּ� root node �ϳ��� �־�� (binary) tree�� �ȴ�
	~BinaryTree();
	Node* CreateNode(int data);
	Node* InsertLeft(Node* parent, int data);
	Node* InsertRight(Node* parent, int data);

	inline void Visit(Node* node) const		// ���
	{
		std::cout << node->mData << " - ";
	}

	void BreadthFirst();
	void DepthFirst();
	void DepthFirstRecursive(Node* pNode);
	int Sum(Node* pNode);
	bool Search(Node* pNode, int data);

	inline Node* GetRoot() const	// const = Ÿ���� ��ȯ�� ������ �Ͻ�
	{
		return mpRoot;
	}
};

