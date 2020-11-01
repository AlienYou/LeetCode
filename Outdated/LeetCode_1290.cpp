/*************************************************************************
	> File Name: LeetCode_1290.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 20 Feb 2020 05:29:11 PM PST
 ************************************************************************/
//二进制链表转整数
#include<iostream>
using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int val) : m_nValue(val), m_pNext(nullptr) {}
};

int GetDecimalValue(ListNode* pHead)
{
    if (pHead == nullptr)
        return 0;
    int base10 = 0;

    ListNode* pNode = pHead;
    while (pNode != nullptr)
    {    
        base10 = base10 * 2 + pNode->m_nValue;
        pNode = pNode->m_pNext;
    }
     return base10;
}

void ConnectNodes(ListNode* pNode, ListNode* pNext)
{
    if (pNode != nullptr)
        pNode->m_pNext = pNext;
}

void test(const char* testName, ListNode* pHead, int expectedBase10)
{
    if (testName == nullptr)
        return ;
    printf("%s:", testName);
    if (GetDecimalValue(pHead) == expectedBase10)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void test1()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(0);
    ListNode* pNode3 = new ListNode(1);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode2, pNode3);

    test("Test1", pNode1, 5);
}

void test2()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(1);
    ListNode* pNode4 = new ListNode(1);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode2, pNode3);
    ConnectNodes(pNode3, pNode4);

    test("Test2", pNode1, 15);
}

void test3()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(0);
    ListNode* pNode3 = new ListNode(0);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode2, pNode3);

    test("Test3", pNode1, 4);
}

int main()
{
    test1();
    test2();
    test3();
}

