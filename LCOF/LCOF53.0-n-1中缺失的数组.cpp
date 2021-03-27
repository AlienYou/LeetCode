class Solution {
public:
    int missingNumber1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i != nums[i])
                return i;
        }
        return nums.size();
    }
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > mid)
                right = mid;
            else 
                left = mid + 1;
        }
        return left;
    }
};