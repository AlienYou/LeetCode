class Solution {
public:
    vector<int> getLeastNumbers1(vector<int>& arr, int k) {
        priority_queue<int> que;
        for (int i = 0; i < arr.size(); ++i) {
            if (que.size() >= k) {
                if (!que.empty() && que.top() > arr[i]) {
                    que.pop();
                    que.push(arr[i]);
                }
            } else 
                que.push(arr[i]);
        }
        vector<int> res;
        while (!que.empty()) {
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }

    int partition(vector<int>& nums, int l, int r) {
        int small = l;
        for (int i = l; i < r; ++i) {
            if (nums[i] < nums[r]) {
                if (small != i) {
                    swap(nums[i], nums[small]);
                }
                ++small;
            }
        }
        swap(nums[r], nums[small]);
        return small;
    }

    void randomizeSelected(vector<int>& nums, int l, int r, int k) {
        if (l >= r)
            return;
        int ind = rand() % (r - l + 1) + l;
        swap(nums[r], nums[ind]);
        int pos = partition(nums, l, r);
        if (pos + 1 == k)
            return;
        else if (pos + 1 > k)
            randomizeSelected(nums, l, pos - 1, k);
        else 
            randomizeSelected(nums, pos + 1, r, k);
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        if (k == 0)
            return res;
        srand((unsigned)time(NULL));
        randomizeSelected(arr, 0, arr.size() - 1, k);
        for (int i = 0; i < k; ++i) 
            res[i] = arr[i];
        return res;
    }
};