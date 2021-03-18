class Solution {
public:
    int findRepeatNumber1(vector<int>& nums) {
        unordered_set<int> set;
        for (const auto& ele : nums) {
            if (set.count(ele))
                return ele;
            set.insert(ele);
        }
        return -1;
    }
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i) {
                int next = nums[nums[i]];
                if (nums[nums[i]] == nums[i])
                    return nums[i];
                nums[nums[i]] = nums[i];
                i = next;
            }
        }
        return -1;
    }
};