class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        int head = -1;
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if (!st2.empty()) {
            head = st2.top();
            st2.pop();
        }
        return head;
    }
private:
    stack<int> st1;
    stack<int> st2;
};
