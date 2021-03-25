class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        maxQue.push(num);
        minQue.push(maxQue.top());
        maxQue.pop();
        if (maxQue.size() < minQue.size()) {
            maxQue.push(minQue.top());
            minQue.pop();
        }
    }
    
    double findMedian() {
        return minQue.size() < maxQue.size() ? maxQue.top() : (double)(minQue.top() + maxQue.top()) / 2;
    }
private:
    priority_queue<int> maxQue;
    priority_queue<int, vector<int>, greater<int>> minQue;
};