class Solution {
public:
    int minArray(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else if (nums[mid] > nums[right])
                left = mid + 1;
            else 
                right--;
        }
        return nums[left];
    }
    
    int binarySearch(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        if (nums[left] >= nums[right]) {
            if (nums[left] > nums[mid])
                return binarySearch(nums, left, mid);
            else {
                int lv = binarySearch(nums, left, mid - 1);
                int rv = binarySearch(nums, mid + 1, right);
                return min(lv, rv);
            }
        }
        return binarySearch(nums, left, mid - 1);
    }
};