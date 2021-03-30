/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 *
 * https://leetcode.com/problems/reconstruct-original-digits-from-english/description/
 *
 * algorithms
 * Medium (47.33%)
 * Likes:    304
 * Dislikes: 930
 * Total Accepted:    38K
 * Total Submissions: 75.5K
 * Testcase Example:  '"owoztneoer"'
 *
 * Given a non-empty string containing an out-of-order English representation
 * of digits 0-9, output the digits in ascending order.
 * 
 * Note:
 * 
 * Input contains only lowercase English letters.
 * Input is guaranteed to be valid and can be transformed to its original
 * digits. That means invalid inputs such as "abc" or "zerone" are not
 * permitted.
 * Input length is less than 50,000.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "owoztneoer"
 * 
 * Output: "012"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "fviefuro"
 * 
 * Output: "45"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> number = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string originalDigits(string s) {
        vector<int> count(10, 0);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'z') count[0]++; //0
            else if (s[i] == 'w') count[2]++; // 2
            else if (s[i] == 'x') count[6]++; // 6
            else if (s[i] == 's') count[7]++; //7-6
            else if (s[i] == 'g') count[8]++; //8
            else if (s[i] == 'h') count[3]++; //3-8
            else if (s[i] == 'u') count[4]++; //4
            else if (s[i] == 'f') count[5]++; //5-4
            else if (s[i] == 'i') count[9]++; //9-8-6-5;
            else if (s[i] == 'o') count[1]++; //1-0-2-4
        }
        count[7] -= count[6];
        count[3] -= count[8];
        count[5] -= count[4];
        count[9] -= count[8] + count[6] + count[5];
        count[1] -= count[0] + count[2] + count[4];
        string res;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < count[i]; ++j)
                res.push_back(i + '0');
        }
        return res;
    }
};
// @lc code=end

