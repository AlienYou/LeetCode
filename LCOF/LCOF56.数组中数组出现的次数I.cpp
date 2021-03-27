class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int allBit = 0;
        for (int i = 0; i < nums.size(); i++) {
            allBit ^= nums[i];
        }
        int bitMask = allBit & (-allBit);
        int A = 0;
        int B = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (bitMask & nums[i])
                A ^= nums[i];
            else 
                B ^= nums[i];
        }
        return {A, B};
    }
};