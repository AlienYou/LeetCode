class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        st.push(x);
        if (!stMin.empty() && stMin.top() < x)
            stMin.push(stMin.top());
        else 
            stMin.push(x);
    }
    
    void pop() {
        if (st.empty())
            return;
        st.pop();
        stMin.pop();
    }
    
    int top() {
        if (!st.empty())
            return st.top();
        return -1;
    }   
    
    int min() {
        if (!stMin.empty())
            return stMin.top();
        return -1;
    }
private:
    stack<int> st;
    stack<int> stMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */