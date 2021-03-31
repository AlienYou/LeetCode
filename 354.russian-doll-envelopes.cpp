/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (36.03%)
 * Likes:    1921
 * Dislikes: 57
 * Total Accepted:    99.3K
 * Total Submissions: 264.2K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi]
 * represents the width and the height of an envelope.
 * 
 * One envelope can fit into another if and only if both the width and height
 * of one envelope are greater than the other envelope's width and height.
 * 
 * Return the maximum number of envelopes you can Russian doll (i.e., put one
 * inside the other).
 * 
 * Note: You cannot rotate an envelope.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: envelopes = [[1,1],[1,1],[1,1]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= envelopes.length <= 5000
 * envelopes[i].length == 2
 * 1 <= wi, hi <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 0)
            return 0;
        /*auto cmp = [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] < v2[0])
                return true;
            return v1[1] < v2[1];        
        };*/
        auto cmp = [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] == v2[0])
                return v1[1] < v2[1];
            return v1[0] < v2[0];        
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        int res = 0;
        vector<int> dp(envelopes.size(), 0);
        dp[0] = 1;
        for (int i = 0; i < envelopes.size(); ++i) {
            int maxV = 0;
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    maxV = max(maxV, dp[j]);
            }
            dp[i] = maxV + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

