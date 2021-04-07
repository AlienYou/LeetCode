/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 *
 * https://leetcode.com/problems/determine-if-string-halves-are-alike/description/
 *
 * algorithms
 * Easy (78.45%)
 * Likes:    207
 * Dislikes: 14
 * Total Accepted:    32.4K
 * Total Submissions: 41.4K
 * Testcase Example:  '"book"'
 *
 * You are given a string s of even length. Split this string into two halves
 * of equal lengths, and let a be the first half and b be the second half.
 * 
 * Two strings are alike if they have the same number of vowels ('a', 'e', 'i',
 * 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and
 * lowercase letters.
 * 
 * Return true if a and b are alike. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "book"
 * Output: true
 * Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel.
 * Therefore, they are alike.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "textbook"
 * Output: false
 * Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2.
 * Therefore, they are not alike.
 * Notice that the vowel o is counted twice.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "MerryChristmas"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "AbCdEfGh"
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= s.length <= 1000
 * s.length is even.
 * s consists of uppercase and lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    inline bool getIndex(char a) {
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
            return true;
        return false;
    } 
    bool halvesAreAlike(string s) {
        int left = 0, right = 0;
        int mid = s.length() >> 1;
        for (int i = 0; i < mid; ++i)
            if (getIndex(s[i]))
                left++;
        for (int i = mid; i < s.length(); ++i)
            if (getIndex(s[i]))
                right++;
        return left == right;
    }
};
// @lc code=end

