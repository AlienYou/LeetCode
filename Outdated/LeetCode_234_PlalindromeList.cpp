/*************************************************************************
	> File Name: LeetCode_234_PlalindromeList.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Feb 2020 09:39:31 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
struct ListNode
{
    T m_nValue;
    ListNode* m_pNext;
    ListNode(T value) : m_nValue(value), m_pNext(nullptr) {}
};

ListNode<int>* pFront = nullptr;

template<typename T>
void ConnectNodes(ListNode<T>* pNode, ListNode<T>* pNext)
{
    if (pNode == nullptr)
        return;
    pNode->m_pNext = pNext;
}

template<typename T>
void DestroyList(ListNode<T>* pHead)
{
    if (pHead != nullptr)
    {
        DestroyList(pHead->m_pNext);
        delete pHead;
    }
}

template<typename T>
bool IsPlalindrome_Recursively(ListNode<T>* pCurrent)
{
    if (pCurrent != nullptr)
    {
        if (!IsPlalindrome_Recursively(pCurrent->m_pNext))   return false;
        if (pFront->m_nValue != pCurrent->m_nValue) return false;
            pFront = pFront->m_pNext;
    }   

    return true;
}

template<typename T>
ListNode<T>* ReverseList(ListNode<T>* pHead)
{
    if (pHead == nullptr)
        return nullptr;
    ListNode<T>* pReverseNext = nullptr;
    ListNode<T>* pReverseCurr = pHead;
    ListNode<T>* pNode = pHead;
    while (pNode != nullptr)
    {
        pNode = pNode->m_pNext;
        pReverseCurr->m_pNext = pReverseNext;
        pReverseNext = pReverseCurr;
        pReverseCurr = pNode;
    }
    return pReverseNext;
}

template<typename T>
bool IsPlalindrome_Circulation(ListNode<T>* pHead)
{
    if (pHead == nullptr)
        return true;
    ListNode<T>* pSlow = pHead;
    ListNode<T>* pFast = pHead;
    
    while (pFast->m_pNext != nullptr && pFast->m_pNext->m_pNext != nullptr)
    {
        pFast = pFast->m_pNext->m_pNext;
        pSlow = pSlow->m_pNext;
    }

    ListNode<T>* pReverHead = ReverseList(pSlow->m_pNext);

    ListNode<T>* pNode = pHead;
    ListNode<T>* pReverNode = pReverHead;

    while (pReverNode !=nullptr)
    {
        if (pReverNode->m_nValue != pNode->m_nValue)
            return false;
        pReverNode = pReverNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return true;
}

template<typename T>
void test(const char* testName, ListNode<T>* pHead, bool expected)
{
    if (testName == nullptr)
        return;
    printf("%s:\n", testName);
    pFront = pHead;
    ListNode<T>* pCurrent = pHead;
    if (IsPlalindrome_Recursively(pCurrent) == expected)
        printf("Method_1: Passed.\n");
    else
        printf("Method_1: Failed.\n");
    if (IsPlalindrome_Circulation(pHead) == expected)
        printf("Method_2: Passed.\n");
    else
        printf("Method_2: Failed.\n");
}

template<typename T>
void testReverseList(const char* testName, ListNode<T>* pHead)
{
    if (testName == nullptr)
        return;
    printf("Reverse %s:", testName);
    ListNode<T>* pReHead = ReverseList(pHead);
    ListNode<T>* pNode = pReHead;
    while (pNode != nullptr)
    {
        cout << pNode->m_nValue << " ";
        pNode = pNode->m_pNext;
    }
    printf("\n");
}

void test1()
{
    ListNode<int>* pNode1 = new ListNode<int>(1);
    ListNode<int>* pNode2 = new ListNode<int>(2);
    ListNode<int>* pNode3 = new ListNode<int>(3);
    ListNode<int>* pNode4 = new ListNode<int>(2);
    ListNode<int>* pNode5 = new ListNode<int>(1);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode2, pNode3);
    ConnectNodes(pNode3, pNode4);
    ConnectNodes(pNode4, pNode5);

    test("Test1", pNode1, true);
    //testReverseList("Test1", pNode1);
} 
 
void test2()
{
    ListNode<int>* pNode1 = new ListNode<int>(2);
    ListNode<int>* pNode2 = new ListNode<int>(1);
    ListNode<int>* pNode3 = new ListNode<int>(1);
    ListNode<int>* pNode4 = new ListNode<int>(2);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode2, pNode3);
    ConnectNodes(pNode3, pNode4);

    test("Test2", pNode1, true);
}

void test3()
{
    ListNode<int>* pNode1 = new ListNode<int>(2);
    ListNode<int>* pNode2 = new ListNode<int>(1);
    ListNode<int>* pNode3 = new ListNode<int>(1);
    ListNode<int>* pNode4 = new ListNode<int>(3);

    ConnectNodes(pNode1, pNode2);
    ConnectNodes(pNode2, pNode3);
    ConnectNodes(pNode3, pNode4);

    test("Test3", pNode1, false);
}

void test4()
{
    ListNode<int>* pHead = nullptr;
    test("Test4", pHead, true);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
}
