class Solution {
public:
    int res = 0;
    void mergeCore(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
        for (int i = left; i <= right; ++i) temp[i] = nums[i];
        int i = left, j = mid + 1;
        for (int cur = left; cur <= right; ++cur) {
            if (i >= mid + 1) nums[cur] = temp[j++];
            else if (j > right) {
                nums[cur] = temp[i++];
            } else if (temp[i] > temp[j]) {
                res += mid - i + 1;
                nums[cur] = temp[j++];
            }
            else 
                nums[cur] = temp[i++];
        }
    }

    void merge(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left >= right)  return;
        int mid = left + (right - left) / 2;
        merge(nums, temp, left, mid);
        merge(nums, temp, mid + 1, right);
        mergeCore(nums, temp, left, mid, right);
    }

    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        merge(nums, temp, 0, nums.size() - 1);
        return res;
    }
};