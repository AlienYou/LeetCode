/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (55.76%)
 * Likes:    3366
 * Dislikes: 177
 * Total Accepted:    243.7K
 * Total Submissions: 433.9K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given an n x n matrix where each of the rows and columns are sorted in
 * ascending order, return the k^th smallest element in the matrix.
 * 
 * Note that it is the k^th smallest element in the sorted order, not the k^th
 * distinct element.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output: 13
 * Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and
 * the 8^th smallest number is 13
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[-5]], k = 1
 * Output: -5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length
 * n == matrix[i].length
 * 1 <= n <= 300
 * -10^9 <= matrix[i][j] <= -10^9
 * All the rows and columns of matrix are guaranteed to be sorted in
 * non-degreasing order.
 * 1 <= k <= n^2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    using Tuple = tuple<int, int, int>;
    
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        auto cmp = [](const Tuple& tup1, const Tuple& tup2) {
            return get<0>(tup1) > get<0>(tup2);  
        };
        priority_queue<Tuple, vector<Tuple>, decltype(cmp)> que(cmp);
        int n = matrix.size();
        for (int i = 0; i < n; ++i) 
            que.push(make_tuple(matrix[0][i], 0, i));
        
        int count = 0;
        for (int i = 2; i <= k; ++i) {
            auto [cur, x, y] = que.top();
            que.pop();
            if (x + 1 < n)
                que.push(make_tuple(matrix[x + 1][y], x + 1, y));
        }
        return get<0>(que.top());
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int j = n - 1, count = 0;
            for (int i = 0; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > mid) --j;
                count += j + 1;
            }
            if (count < k)
                left = mid + 1;
            else 
                right = mid;
        }
        return left;
    }
};
// @lc code=end

