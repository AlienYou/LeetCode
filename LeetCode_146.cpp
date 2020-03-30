/*************************************************************************
	> File Name: LeetCode_146.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Mar 2020 02:30:06 AM PDT
 ************************************************************************/

#include<iostream>
#include<utility>
#include<unordered_map>
using namespace std;

typedef int Key_type;
typedef int value_type;

class DoubleList
{
public:
    struct Node
    {
        Key_type m_nKey;
        value_type m_nValue;
        Node* m_pNext;
        Node* m_pPre;
        Node(Key_type k, value_type v) : m_nKey(k), m_nValue(v), m_pNext(nullptr), m_pPre(nullptr)
        {}
    };

    DoubleList()
    {
        head = new Node(0, 0);
        last = new Node(0, 0);
        head->m_pPre = nullptr;
        head->m_pNext = last;
        last->m_pPre = head;
        last->m_pNext = nullptr;
        size = 0;
    }

    bool InsertNodeAtBeginning(Node* pNode)
    {
        if (pNode == nullptr)
            return false;
        pNode->m_pPre = head;
        pNode->m_pNext = head->m_pNext;
        head->m_pNext->m_pPre = pNode;
        head->m_pNext = pNode;
        ++size;
        return true;
    }

    const Node* getHead() const { return head; }

    bool RemoveNode(Node* pNode)
    {
        if (pNode == nullptr || pNode->m_pNext == nullptr || pNode->m_pPre == nullptr)
            return false;
        pNode->m_pNext->m_pPre = pNode->m_pPre;
        pNode->m_pPre->m_pNext = pNode->m_pNext;
        delete pNode;
        --size;
        return true;
    }
    bool MoveToBeginning(Node* pNode)
    {
        if (pNode == nullptr)
            return false;
        pNode->m_pNext->m_pPre = pNode->m_pPre;
        pNode->m_pPre->m_pNext = pNode->m_pNext;
        pNode->m_pPre = head;
        pNode->m_pNext = head->m_pNext;
        head->m_pNext->m_pPre = pNode;
        head->m_pNext = pNode;
        return true;
    }
    void Clear()
    {
        Node* pNode = head->m_pNext;
        while (pNode != last)
        {
            Node* pDel = pNode;
            pNode = pNode->m_pNext;
            delete pDel;
            --size;
        }
        head->m_pNext = last;
        last->m_pPre = head;
    }
    
    const Node* getLast() const
    {
        return last;
    }

    int Size() const
    {
        return size;
    }

    ~DoubleList()
    {
        Clear();
        delete head;
        delete last;
        head == nullptr;
        last == nullptr;
    }

private:
    Node* head;
    Node* last;
    int size;
};

class LRUCache
{
public:
    using Node = DoubleList::Node;
    using mIt = unordered_map<int, Node*>::iterator;
    LRUCache(int initSize = 0) : MaxSize(initSize), curSize(0)
    {
        
    }

    int get(int key)
    {
        mIt it = lruMap.find(key);
        if (it == lruMap.end())
        {
            return -1;
        }
        //需要调整key的位置
        put(key, it->second->m_nValue);
        return it->second->m_nValue;
    }

    void put(int key, int value)
    {
        if (lruMap.find(key) != lruMap.end())
        {
            //dl.RemoveNode(lruMap[key]);
            lruMap[key]->m_nValue = value;
            dl.MoveToBeginning(lruMap[key]);   
        }
        else
        {
            Node* pNewNode = new Node(key, value);
            if (curSize >= MaxSize)
            {
                lruMap.erase(dl.getLast()->m_pPre->m_nKey);
                dl.RemoveNode(dl.getLast()->m_pPre);
            }
            lruMap.insert(make_pair(key, pNewNode));
            dl.InsertNodeAtBeginning(pNewNode);
            ++curSize;
        }
        
    }
    int getSize() const { return curSize; }
    const DoubleList& getCache() { return dl; }
private:
    unordered_map<int, Node*> lruMap;
    DoubleList dl;
    int MaxSize;
    int curSize;
};


void PrintList(const DoubleList& dl) 
{
    if (dl.Size() == 0)
        return ;
    using Node = DoubleList::Node;
    const Node* head = dl.getHead();
    while (head->m_pNext != nullptr)
    {
        printf("%d %d\n", head->m_nKey, head->m_nValue);
        head = head->m_pNext;
    }
    printf("\n");
}

void PrintListReverse(const DoubleList& dl)
{
    if (dl.Size() == 0)
        return ;
    using Node = DoubleList::Node;
    const Node* last = dl.getLast();
    while (last->m_pPre != nullptr)
    {
        printf("%d %d\n", last->m_nKey, last->m_nValue);
        last = last->m_pPre;
    }
    printf("\n");
}

void testList()
{
    using Node = DoubleList::Node;
    DoubleList dl;
    dl.InsertNodeAtBeginning(new Node(1, 1));
    dl.InsertNodeAtBeginning(new Node(2, 2));
    dl.InsertNodeAtBeginning(new Node(3, 3));
    PrintListReverse(dl);
    PrintList(dl);
    const Node* pNode = dl.getHead();
    dl.RemoveNode(pNode->m_pNext);
    PrintList(dl);
    PrintListReverse(dl);
}

void testLRU()
{
    LRUCache lruTest(3);
    lruTest.put(1, 1);
    lruTest.put(2, 2);
    lruTest.put(3, 3);
    PrintList(lruTest.getCache());
    printf("%d\n", lruTest.get(2));
    PrintList(lruTest.getCache());

    lruTest.put(2, 3);
    PrintList(lruTest.getCache());

    lruTest.put(4, 4);
    PrintList(lruTest.getCache());

    lruTest.put(4, 5);
    PrintList(lruTest.getCache());

    lruTest.put(5, 6);
    PrintList(lruTest.getCache());

    printf("%d\n", lruTest.get(2));
    PrintList(lruTest.getCache());
}

int main()
{
    testLRU();
}
