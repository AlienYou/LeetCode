class Solution {
public:
    bool isStraight1(vector<int>& nums) {
        int countJoker = 0, lack = 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        for (; i < nums.size(); ++i) {
            if (!nums[i]) 
                countJoker++;
             else 
                break;
        }
        int r = i + 1;
        while (r < nums.size()) {
            if (nums[r] == nums[r - 1])
                return false;
            if (nums[r] - nums[r - 1] > 1) 
                lack += nums[r] - nums[r - 1] - 1;
            ++r;
        }
        return lack <= countJoker;
    }
    bool isStraight(vector<int>& nums) {
        unordered_set<int> set;
        int maxV = 0;
        int minV = 15;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                continue;
            if (set.count(nums[i]))
                return false;
            maxV = max(maxV, nums[i]);
            minV = min(minV, nums[i]);
            set.insert(nums[i]);
        }
        return maxV - minV < nums.size();
    }
};