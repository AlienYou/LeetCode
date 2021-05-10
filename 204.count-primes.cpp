/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (32.06%)
 * Likes:    2733
 * Dislikes: 725
 * Total Accepted:    438.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 0
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 1
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 5 * 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        for (int i = 2; i * i < n; ++i) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i])
                ++ans;
        }
        return ans;
    }
    
    int countPrimes1(int n) {
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i))
                ans++;
        }
        return ans;
    }
    
    bool isPrime(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

