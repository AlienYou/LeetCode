/*************************************************************************
	> File Name: LeetCode_offer09.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Feb 2020 10:23:56 PM PST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

class CQueue
{
    public:
    CQueue() {  }
        
    void appendTail(int value)
    {
        st1.push(value);
    }

    int deleteHead()
    {
        int head = -1;
        if (st2.size() <= 0)
        {
            while (st1.size() > 0)
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        if (st2.size() > 0)
        {
            head = st2.top();
            st2.pop();
        }
        return head;
    }
    private:
    stack<int> st1;
    stack<int> st2;
};

void test(const char* testName, int head, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (head == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", head);
}

int main()
{
    CQueue* obj = new CQueue;
    obj->appendTail(1);
    obj->appendTail(2);
    obj->appendTail(3);

    test("Test1", obj->deleteHead(), 1);
    test("Test2", obj->deleteHead(), 2);

    obj->appendTail(4);
    obj->appendTail(5);
    obj->appendTail(6);

    test("Test3", obj->deleteHead(), 3);
    test("Test4", obj->deleteHead(), 4);
}


