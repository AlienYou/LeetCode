/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 *
 * https://leetcode.com/problems/arithmetic-slices/description/
 *
 * algorithms
 * Medium (58.42%)
 * Likes:    1410
 * Dislikes: 188
 * Total Accepted:    107.7K
 * Total Submissions: 183.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * A sequence of numbers is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 * 
 * For example, these are arithmetic sequences:
 * 
 * 
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * 
 * The following sequence is not arithmetic.
 * 
 * 
 * 1, 1, 2, 5, 7
 * 
 * 
 * A zero-indexed array A consisting of N numbers is given. A slice of that
 * array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 * 
 * A slice (P, Q) of the array A is called arithmetic if the sequence:
 * A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means
 * that P + 1 < Q.
 * 
 * The function should return the number of arithmetic slices in the array
 * A.
 * 
 * 
 * Example:
 * 
 * 
 * A = [1, 2, 3, 4]
 * 
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3,
 * 4] itself.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices1(vector<int>& A) {
        int count = 0;
        for (int i = 0; i < A.size() - 2; ++i) {
            int diff = A[i + 1] - A[i];
            for (int j = i + 2; j < A.size(); ++j) {
                int k = i + 1;
                for (; k <= j; ++k) {
                    if (A[k] - A[k - 1] != diff)
                        break;
                }
                if (k > j) 
                    ++count;
            }
        }
        return count;
    }

    int numberOfArithmeticSlices2(vector<int>& A) {
        if (A.size() <= 2)
            return 0;
        int count = 0;
        for (int i = 0; i < A.size() - 2; ++i) {
            int diff = A[i + 1] - A[i];
            for (int j = i + 2; j < A.size(); ++j) {
                if (A[j] - A[j - 1] == diff)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
    
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp(A.size(), 0);
        int sum = 0;
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = 1 + dp[i - 1];
                sum += dp[i];
            }
        }
        return sum;
    }
};
// @lc code=end

