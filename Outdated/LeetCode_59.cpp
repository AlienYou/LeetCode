/*************************************************************************
	> File Name: LeetCode_59.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 06 Mar 2020 03:22:55 PM PST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

class MaxQueue
{
    public:
    MaxQueue() {  }

    int max_value() 
    {
        if (!maxQue.empty())
            return maxQue.front();
        return -1;
    }

    void push_back(int value) {  
        numQueue.push(value);
        if (!maxQue.empty() && value > maxQue.back())
        {
            while (!maxQue.empty() && value > maxQue.back())
               maxQue.pop_back(); 
        }
        maxQue.push_back(value);
    }

    int pop_front() {
        int pop = -1;
        if (!numQueue.empty())
        {
            pop = numQueue.front();
            if (pop == maxQue.front())
                maxQue.pop_front();
            numQueue.pop();
            return pop;
        }
        return pop;
    }
    private:
    queue<int> numQueue;
    deque<int> maxQue;
};

void test(const char* testName, int max, int expected)
{
    if (testName == nullptr)
        return;
    printf("%s:", testName);
    if (max == expected)
        printf("Passed.\n");
    else
        printf("%d.Failed.\n", max);
}

int main()
{
    MaxQueue myque;
    test("Test0", myque.max_value(), -1);
    myque.push_back(1);
    myque.push_back(2);
    test("Test1", myque.max_value(), 2);
    test("Test2", myque.pop_front(), 1);
    myque.pop_front();

    myque.push_back(3);
    myque.push_back(4);
    myque.push_back(0);
    test("Test3", myque.max_value(), 4);
    
    myque.pop_front();
    myque.pop_front();
    test("Test4", myque.max_value(), 0);

    myque.push_back(5);
    test("Test5", myque.max_value(), 5);
    
    myque.push_back(0);
    test("Test6", myque.max_value(), 5);
    myque.pop_front();
    myque.pop_front();
    
}
