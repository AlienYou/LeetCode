/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (50.61%)
 * Likes:    9934
 * Dislikes: 151
 * Total Accepted:    675.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == height.length
 * 0 <= n <= 3 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;
        stack<int> st;
        int result = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[st.top()] <= height[i]) {
                int low = st.top();
                st.pop();
                if (!st.empty()) {
                    int h = min(height[st.top()], height[i]);
                    result += (h - height[low]) * (i - st.top() - 1);
                }
            }
            st.push(i);
        }
        return result;
    }
};
};
// @lc code=end

