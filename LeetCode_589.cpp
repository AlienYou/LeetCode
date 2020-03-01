/*************************************************************************
	> File Name: LeetCode_589.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Feb 2020 08:41:53 PM PST
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

    Node() {  }
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _chidlren) { val = _val; children = _chidlren; }
};

vector<int> Preorder(Node* root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    stack<Node*> treeStack;
    treeStack.push(root);
    while (!treeStack.empty())
    {
        Node* pNode = treeStack.top();
        result.push_back(pNode->val);
        treeStack.pop();
        if (pNode->children.size() > 0)
        {
            for (int i = pNode->children.size() - 1; i >= 0; --i)
                treeStack.push(pNode->children[i]);
        }
    }
    return result;
}

void ConnectNodes(Node* pParent, Node* pChild)
{
    if (pParent != nullptr)
    {
        pParent->children.push_back(pChild);
    }
}
void test(const char* testName, Node* root)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    vector<int> result = Preorder(root);
    for (auto &x : result)
        printf("%d ", x);
    printf("\n");
}

void test1()
{
    Node* pNode1 = new Node(1);
    Node* pNode2 = new Node(3);
    Node* pNode3 = new Node(2);
    Node* pNode4 = new Node(4);
    Node* pNode5 = new Node(5);
    Node* pNode6 = new Node(6);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode1, pNode3);
    ConnectNodes(pNode1, pNode4);
    ConnectNodes(pNode2, pNode5);
    ConnectNodes(pNode2, pNode6);
    
    test("Test1", pNode1);
}

int main()
{
    test1();
}
