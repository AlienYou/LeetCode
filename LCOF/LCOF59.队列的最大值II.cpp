class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        return maxQue.size() > 0 ? maxQue.front() : -1;
    }
    
    void push_back(int value) {
        que.push(value);
        if (maxQue.size() > 0) {
            while (!maxQue.empty() && maxQue.back() < value) maxQue.pop_back();
            maxQue.push_back(value);
        } else 
            maxQue.push_back(value);
    }
    
    int pop_front() {
        if (que.size() == 0) return -1;
        int front = que.front();
        que.pop();
        if (front == maxQue.front())
            maxQue.pop_front();
        return front;
    }
private:
    queue<int> que;
    deque<int> maxQue;
};