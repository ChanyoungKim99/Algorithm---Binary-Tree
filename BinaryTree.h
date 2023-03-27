#pragma once
#include <iostream>


// POD 
struct Node					// struct = 모든 멤버가 public인 class
{
	int mData;

	// 자기 참조
	Node* mLeft;
	Node* mRight;

	// 생성자
	Node(int data, Node* left, Node* right) :
		mData{ data }, mLeft{ left }, mRight{right}
	{
	}
};

class BinaryTree
{
private:
	Node* mpRoot;			// root만 안다면, 모두 관리가능
	
public:
	BinaryTree();			// 최소 root node 하나가 있어야 (binary) tree가 된다
	~BinaryTree();
	Node* CreateNode(int data);
	Node* InsertLeft(Node* parent, int data);
	Node* InsertRight(Node* parent, int data);

	inline void Visit(Node* node) const		// 출력
	{
		std::cout << node->mData << " - ";
	}

	void BreadthFirst();
	void DepthFirst();
	void DepthFirstRecursive(Node* pNode);
	int Sum(Node* pNode);
	bool Search(Node* pNode, int data);

	inline Node* GetRoot() const	// const = 타입의 변환이 없음을 암시
	{
		return mpRoot;
	}
};

