/*************************************************************************
	> File Name: LeetCode_590.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 01 Mar 2020 05:20:56 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node
{
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children) { val = _val; children = _children; }
};

void ConnectNodes(Node* pParent, Node* pChild)
{
    if (pParent != nullptr)
    {
        pParent->children.push_back(pChild);
    }
}

void PostOrderCore(Node* root, vector<int>& order)
{
    if (root == nullptr)
        return;
    for (int i = 0; i < root->children.size(); ++i)
        PostOrderCore(root->children[i], order);
    order.push_back(root->val);
}

vector<int> PostOrder_Recursively(Node* root)
{
    vector<int> order;
    if (root == nullptr)
        return order;
    PostOrderCore(root, order);
    return order;
}

vector<int> PostOrder_Iteration(Node* root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    stack<Node*> nodeStack;
    nodeStack.push(root);
    Node* pVisited = nullptr;
    while (!nodeStack.empty())
    {
        Node* pNode = nodeStack.top();
        int n = pNode->children.size();
        if (n > 0 && pNode->children[n - 1] != pVisited)
        {
            for (int i = n - 1; i >= 0; --i)
                nodeStack.push(pNode->children[i]);
        }
        else
        {
            result.push_back(pNode->val);
            pVisited = pNode;
            nodeStack.pop();
        }
    }
    return result;
}

void test(const char* testName, Node* root)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    vector<int> result = PostOrder_Recursively(root);
    printf("\nMethod1:");
    for (auto &x : result)
        printf("%d ", x);
    printf("\n");
    printf("Method2:");
    vector<int> result2 = PostOrder_Iteration(root);
    for (auto &y : result2)
        printf("%d ", y);
    printf("\n");
}

void test1()
{
    Node* pNode1 = new Node(1);
    Node* pNode2 = new Node(2);
    Node* pNode3 = new Node(3);
    Node* pNode4 = new Node(4);
    Node* pNode5 = new Node(5);
    Node* pNode6 = new Node(6);
    Node* pNode7 = new Node(7);
    Node* pNode8 = new Node(8);
    Node* pNode9 = new Node(9);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode1, pNode3);
    ConnectNodes(pNode1, pNode4);
    ConnectNodes(pNode3, pNode5);
    ConnectNodes(pNode3, pNode6);
    ConnectNodes(pNode3, pNode7);
    ConnectNodes(pNode4, pNode8);
    ConnectNodes(pNode8, pNode9);

    test("Test1", pNode1);
}

void test2()
{
    Node* pNode1 = new Node(1);
    test("Test2", pNode1);
}

int main()
{
    test1();
    test2();
}
