/*************************************************************************
	> File Name: LeetCode_225.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 May 2020 02:04:22 AM PDT
 ************************************************************************/

#include<iostream>
#include<queue>

using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (que1.empty())
            que1.push(x);
        else
        {
            while (!que1.empty())
            {
                que2.push(que1.front());
                que1.pop();
            }
            que1.push(x);
            while (!que2.empty())
            {
                que1.push(que2.front());
                que2.pop();
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = -1;
        if (!que1.empty())
        { 
            top = que1.front();
            que1.pop();
        }
        return top;
    }
    
    /** Get the top element. */
    int top() {
        if (que1.empty())
            return -1;
        return que1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (!que1.empty())
            return false;;
        return true;
    }
private:
    queue<int> que1;
    queue<int> que2;
};
