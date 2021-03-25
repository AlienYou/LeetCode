/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 *
 * https://leetcode.com/problems/3sum-with-multiplicity/description/
 *
 * algorithms
 * Medium (35.99%)
 * Likes:    633
 * Dislikes: 119
 * Total Accepted:    36.5K
 * Total Submissions: 90K
 * Testcase Example:  '[1,1,2,2,3,3,4,4,5,5]\n8'
 *
 * Given an integer array arr, and an integer target, return the number of
 * tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
 * 
 * As the answer can be very large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
 * Output: 20
 * Explanation: 
 * Enumerating by the values (arr[i], arr[j], arr[k]):
 * (1, 2, 5) occurs 8 times;
 * (1, 3, 4) occurs 8 times;
 * (2, 2, 4) occurs 2 times;
 * (2, 3, 3) occurs 2 times.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,1,2,2,2,2], target = 5
 * Output: 12
 * Explanation: 
 * arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
 * We choose one 1 from [1,1] in 2 ways,
 * and two 2s from [2,2,2,2] in 6 ways.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= arr.length <= 3000
 * 0 <= arr[i] <= 100
 * 0 <= target <= 300
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        int n = arr.size() - 2;
        int L = arr.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = L - 1;
            int rest = target - arr[i];
            while (left < right) {
                if (arr[left] + arr[right] > rest)
                    --right;
                else if (arr[left] + arr[right] < rest)
                    ++left;
                else if (arr[left] != arr[right]) {
                    int lc = 1, rc = 1;
                    while (left + 1 < right && arr[left] == arr[left + 1]) {
                        ++lc;
                        ++left;
                    }
                    while (left < right - 1 && arr[right] == arr[right - 1]) {
                        ++rc;
                        --right;
                    }
                    res += lc * rc;
                    res %= mod;
                    ++left;
                    --right;
                } else {
                    res += (right - left + 1) * (right - left) / 2;
                    res %= mod;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

