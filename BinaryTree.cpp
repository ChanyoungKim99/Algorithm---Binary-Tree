#include "BinaryTree.h"
#include <queue>			// Breath-First Algorithm 사용
#include <stack>            // Depth-First Algorithm 사용

BinaryTree::BinaryTree() 
{
    mpRoot = CreateNode(0);
}

BinaryTree::~BinaryTree()
{
    // Delete는 post-order로!
}

Node* BinaryTree::CreateNode(int data)
{
    return new Node(data, nullptr, nullptr);
}

Node* BinaryTree::InsertLeft(Node* parent, int data)
{
    parent->mLeft = CreateNode(data);
    return parent->mLeft;
}

Node* BinaryTree::InsertRight(Node* parent, int data)
{
    parent->mRight = CreateNode(data);
    return parent->mRight;
}

void BinaryTree::BreadthFirst()
{
    std::queue<Node*> q;

    q.push(mpRoot);

    while (!q.empty())
    {
        auto node = q.front();
        Visit(node);
        q.pop();

        if (node->mLeft)            // = if (node->mLeft != nullptr)
        {                           // 거짓 = 0 또는 nullptr, 참 = 0이 아닌 나머지 숫자, 포인터
            q.push(node->mLeft);
        }
        if (node->mRight)
        {
            q.push(node->mRight);
        }
    }
    // Time Complexity = O(n)   실행횟수
    // Space Complexity = O(n)  변수갯수
}

void BinaryTree::DepthFirst()
{
    std::stack<Node*> s;
    s.push(mpRoot);

    while (!s.empty())
    {
        auto node = s.top();
        Visit(node);
        s.pop();

        if (node->mRight)
        {
            s.push(node->mRight);
        }
        if (node->mLeft)
        {
            s.push(node->mLeft);
        }
    }
    // Time Complexity = O(n)   실행횟수
    // Space Complexity = O(n)  변수갯수
}

void BinaryTree::DepthFirstRecursive(Node* pNode)
{
    // base case
    if (!pNode)
    {
        return;
    }

    // recursive case
    //Visit(pNode);                            // pre-order
    //DepthFirstRecursive(pNode->mLeft);
    //DepthFirstRecursive(pNode->mRight);

    //DepthFirstRecursive(pNode->mLeft);       // in-order
    //Visit(pNode);                
    //DepthFirstRecursive(pNode->mRight);

    DepthFirstRecursive(pNode->mLeft);       // post-order
    DepthFirstRecursive(pNode->mRight);
    Visit(pNode);               

}

int BinaryTree::Sum(Node* pNode)
{
    if (!pNode)         // = if(pNode == nullptr)
    {
        return 0;
    }

    return pNode->mData + Sum(pNode->mLeft) + Sum(pNode->mRight);
}   // 부분원소를 더하는 것이 아니라 "부분집합"을 더하는 것이다!!!

bool BinaryTree::Search(Node* pNode, int data)
{
    if (!pNode)
    {
        return false;
    }

    if (pNode->mData == data || Search(pNode->mLeft, data) || Search(pNode->mRight, data))
    {
        return true;
    }
    else
    {
        return false;
    }
}

