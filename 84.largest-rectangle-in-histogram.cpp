/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (36.66%)
 * Likes:    5359
 * Dislikes: 105
 * Total Accepted:    341.6K
 * Total Submissions: 919.3K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given an array of integers heights representing the histogram's bar height
 * where the width of each bar is 1, return the area of the largest rectangle
 * in the histogram.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10
 * units.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: heights = [2,4]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= heights.length <= 10^5
 * 0 <= heights[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea1(vector<int>& heights) {
        int size = heights.size();
        vector<int> left(size, 0);
        vector<int> right(size, size - 1);
        
        for (int i = 0; i < size; ++i) {
            int cur = i - 1;
            while (cur >= 0 && heights[cur] >= heights[i])
                cur = left[cur];
            left[i] = cur;
        }
        
        for (int i = size - 1; i >= 0; --i) {
            int cur = i + 1;
            while (cur < size && heights[cur] >= heights[i])
                cur = right[cur];
            right[i] = cur;
        }
        
        int result = 0;
        for (int i = 0; i < size; ++i) {
            result = max(result, heights[i] * (right[i] - left[i] - 1));
        }
        return result;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(0);
        int n = heights.size();
        int result = 0;
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {
                int cur = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                result = max(result, (i - left - 1) * heights[cur]);
            }
            st.push(i);
        }
        
        return result;
    }
};
// @lc code=end

