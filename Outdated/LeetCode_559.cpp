/*************************************************************************
	> File Name: LeetCode_559.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Mar 2020 08:57:44 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node
{
    public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};

void ConnectNodes(Node* pParet, Node* pChild)
{
    if (pParet != nullptr)
    {
        pParet->children.push_back(pChild);
    }
}

int MaxDepth(Node* root)
{
    if (root == nullptr)
        return 0;
    int level = 1;
    queue<Node*> nodeQue;
    nodeQue.push(root);
    while (!nodeQue.empty())
    {
        int length = nodeQue.size();
        for (int i = 0; i < length; ++i)
        {
            Node* pNode = nodeQue.front();
            nodeQue.pop();
            int chil = pNode->children.size();
            for (int j = 0; j < chil; ++j)
            {
                nodeQue.push(pNode->children[j]);
            }
        }
        if (!nodeQue.empty())
            ++level;
    }
    return level;
}

int MaxDepth_Recursively(Node* root)
{
    if (root == nullptr)
        return 0;
    int max = 0;
    for (int i = 0; i < root->children.size(); ++i)
    {
        int cur = MaxDepth_Recursively(root->children[i]);
        if (cur > max)
            max = cur;
    }
    return max + 1;
}

void test(const char* testName, Node* root, int depth)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    int actual = MaxDepth_Recursively(root);
    if (actual == depth)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", actual);
}

void test1()
{
    Node* pNode1 = new Node(1);
    Node* pNode2 = new Node(2);
    Node* pNode3 = new Node(3);
    Node* pNode4 = new Node(4);
    Node* pNode5 = new Node(5);
    Node* pNode6 = new Node(6);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode1, pNode3);
    ConnectNodes(pNode1, pNode4);
    ConnectNodes(pNode2, pNode5);
    ConnectNodes(pNode2, pNode6);
    
    test("Test1", pNode1, 3);
}

int main()
{
    test1();
}
