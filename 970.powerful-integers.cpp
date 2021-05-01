/*
 * @lc app=leetcode id=970 lang=cpp
 *
 * [970] Powerful Integers
 *
 * https://leetcode.com/problems/powerful-integers/description/
 *
 * algorithms
 * Easy (39.94%)
 * Likes:    126
 * Dislikes: 52
 * Total Accepted:    38.9K
 * Total Submissions: 90.9K
 * Testcase Example:  '2\n3\n10'
 *
 * Given three integers x, y, and bound, return a list of all the powerful
 * integers that have a value less than or equal to bound.
 * 
 * An integer is powerful if it can be represented as x^i + y^j for some
 * integers i >= 0 and j >= 0.
 * 
 * You may return the answer in any order. In your answer, each value should
 * occur at most once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 2, y = 3, bound = 10
 * Output: [2,3,4,5,7,9,10]
 * Explanation:
 * 2 = 2^0 + 3^0
 * 3 = 2^1 + 3^0
 * 4 = 2^0 + 3^1
 * 5 = 2^1 + 3^1
 * 7 = 2^2 + 3^1
 * 9 = 2^3 + 3^0
 * 10 = 2^0 + 3^2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 3, y = 5, bound = 15
 * Output: [2,4,6,8,10,14]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= x, y <= 100
 * 0 <= bound <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int x1 = 1;
        unordered_set<int> map;
        for (int i = 0; x1 < bound; x1 *= x, i++) {
            int y1 = 1;
            for (int j = 0; x1 + y1 <= bound; y1 *= y) {
                int sum = x1 + y1;
                if (!map.count(sum)) {
                    map.insert(sum);
                }
                if (y == 1) 
                    break;
            }
            if (x == 1)
                break;
        }
        return vector<int>(map.begin(), map.end());
    }
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int a = x == 1 ? 0 : (int)(log(bound) / log(x));
        int b = y == 1 ? 0 : (int)(log(bound) / log(y));
        unordered_set<int> set;
        
        for (int i = 0; i <= a; ++i) {
            for (int j = 0; j <= b; ++j) {
                int sum = (int)pow(x, i) + pow(y, j);
                if (sum <= bound)
                    set.insert(sum);
            }
        }
        return vector<int>(set.begin(), set.end());
    }
};
// @lc code=end

