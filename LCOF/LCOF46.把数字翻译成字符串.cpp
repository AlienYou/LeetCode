class Solution {
public:
    int translateNum1(int num) {
        vector<int> bit;
        while (num) {
            bit.push_back(num % 10);
            num /= 10;
        }   
        int size = bit.size();
        vector<int> dp(size + 1, 0);
        dp[size] = 1;

        for (int i = size - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            if (i + 1 < size && bit[i + 1] != 0 && canTrans(bit[i] + bit[i + 1] * 10))
                dp[i] += dp[i + 2]; 
        }
        return dp[0];
    }
    bool canTrans(int n) {
        if (n >= 0 && n <= 25)
            return true;
        return false;
    }
    int translateNum(int num) {
        vector<int> bit;
        while (num) {
            bit.push_back(num % 10);
            num /= 10;
        }   
        int pre = 1, formTwo = 1;
        for (int i = size - 1; i >= 0; i--) {
            int cur = pre;
            if (i + 1 < size && bit[i + 1] != 0 && canTrans(bit[i] + bit[i + 1] * 10))
                cur += formTwo;
            formTwo = pre;
            pre = cur;
        }
        return pre;
    }
};