// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 *
 * https://leetcode.com/problems/beautiful-arrangement/description/
 *
 * algorithms
 * Medium (61.77%)
 * Likes:    1060
 * Dislikes: 198
 * Total Accepted:    80K
 * Total Submissions: 129.5K
 * Testcase Example:  '2'
 *
 * Suppose you have n integers labeled 1 through n. A permutation of those n
 * integers perm (1-indexed) is considered a beautiful arrangement if for every
 * i (1 <= i <= n), either of the following is true:
 * 
 * 
 * perm[i] is divisible by i.
 * i is divisible by perm[i].
 * 
 * 
 * Given an integer n, return the number of the beautiful arrangements that you
 * can construct.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: 2
 * Explanation: 
 * The first beautiful arrangement is [1,2]:
 * ⁠   - perm[1] = 1 is divisible by i = 1
 * ⁠   - perm[2] = 2 is divisible by i = 2
 * The second beautiful arrangement is [2,1]:
 * ⁠   - perm[1] = 2 is divisible by i = 1
 * ⁠   - i = 2 is divisible by perm[2] = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 15
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int count = 0;
    int countArrangement_method1(int n) {
        vector<int> perm(n);
        for (int i = 0; i < n; ++i) {
            perm[i] = i + 1;
        }
        permutate(perm, 0); 
        return count;
    }
    //dp
    int countArrangement(int n) {
        return dfs(0, n, n);
    }
private:
    int dfs(int mask, int n, int N) {
        if (n == 0)
            return 1;
        int result = 0;
        for (int i = 0; i < N; ++i) {
            if (!(mask & (1 << i)) && (n % (i + 1) == 0 || (i + 1) % n == 0))
                result += dfs(mask ^ (1 << i), n - 1, N);
        }
        return result;
    }

    void permutate(vector<int>& perm, int index) {
        if (index == perm.size()) {
            count++;
        }

        for (int i = index; i < perm.size(); ++i) {
            swap(perm[i], perm[index]);
            if (perm[index] % (index + 1) == 0 || (index + 1) % perm[index] == 0) {
                permutate(perm, index + 1);
            }
            swap(perm[i], perm[index]);
        }
    }
};
// @lc code=end
