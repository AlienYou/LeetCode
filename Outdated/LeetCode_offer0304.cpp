/*************************************************************************
	> File Name: LeetCode_offer0304.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 29 Feb 2020 07:18:08 PM PST
 ************************************************************************/

#include<iostream>
#include<stack>

using namespace std;

class MyQueue
{
    public:
    MyQueue() {  }
    void push(int x) {
        
        while (st2.size() > 0)
        {
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(x);
        while (st1.size() > 0)
        {
            st2.push(st1.top());
            st1.pop();
        }
    }
    int pop()
    {
        int head = -1;
        if (st2.size() > 0)
        {
            head = st2.top();
            st2.pop();
        }
        return head;
    }

    int peek()
    {
        int head = -1;
        if (st2.size() > 0)
            head = st2.top();
        return head;
    }

    bool empty()
    {
       if (st1.empty() && st2.empty())
            return true;
        return false;
    }
    private:
    stack<int> st1;
    stack<int> st2;
};


void test(const char* testName, int top, int expected, bool actual, bool expectedEmpty)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if ((actual == expectedEmpty) && (top == expected))
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", top);
}

int main()
{
    MyQueue queueTest;
    queueTest.push(1);
    queueTest.push(2);
    queueTest.push(3);

    test("Test1", queueTest.peek(), 1, false, false);
    test("Test2", queueTest.pop(), 1, false, false);
    test("Test3", queueTest.pop(), 2, false, false);
    test("Test4", queueTest.pop(), 3, false, false);
    test("Test4", queueTest.pop(), -1, true, true);

}
