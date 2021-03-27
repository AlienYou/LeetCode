class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        if (left == nums.size() || nums[left] != target)
            return 0;
        int right = binarySearch(nums, target, false) - 1;
        return right - left + 1;
    }

    int binarySearch(vector<int>& nums, int target, bool l) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target || (l && nums[mid] == target))
                right = mid;
            else 
                left = mid + 1;
        }
        return left;
    }
};