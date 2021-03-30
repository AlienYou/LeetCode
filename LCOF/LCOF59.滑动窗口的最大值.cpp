class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return vector<int>();
        vector<int> res;
        deque<int> que;
        for (int i = 0; i < nums.size(); ++i) {
            while (!que.empty() && nums[que.back()] < nums[i]) {
                que.pop_back();
            }
            que.push_back(i);
            if (i - que.front() >= k)
                que.pop_front();
            if (i >= k - 1) {
                res.push_back(nums[que.front()]);
            }
        }
        return res;
    }
};