class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int cur = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != cur)
                --count;
            else 
                ++count;
            if (count == 0) {
                cur = nums[i];
                count = 1;
            }
        }
        return cur;
    }
};