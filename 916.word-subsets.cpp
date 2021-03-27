/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 *
 * https://leetcode.com/problems/word-subsets/description/
 *
 * algorithms
 * Medium (48.10%)
 * Likes:    670
 * Dislikes: 103
 * Total Accepted:    41.3K
 * Total Submissions: 78.5K
 * Testcase Example:  '["amazon","apple","facebook","google","leetcode"]\n["e","o"]'
 *
 * We are given two arrays A and B of words.  Each word is a string of
 * lowercase letters.
 * 
 * Now, say that word b is a subset of word a if every letter in b occurs in a,
 * including multiplicity.  For example, "wrr" is a subset of "warrior", but is
 * not a subset of "world".
 * 
 * Now say a word a from A is universal if for every b in B, b is a subset of
 * a. 
 * 
 * Return a list of all universal words in A.  You can return the words in any
 * order.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
 * Output: ["facebook","google","leetcode"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
 * Output: ["apple","google","leetcode"]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
 * Output: ["facebook","google"]
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B =
 * ["lo","eo"]
 * Output: ["google","leetcode"]
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B =
 * ["ec","oc","ceo"]
 * Output: ["facebook","leetcode"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length, B.length <= 10000
 * 1 <= A[i].length, B[i].length <= 10
 * A[i] and B[i] consist only of lowercase letters.
 * All words in A[i] are unique: there isn't i != j with A[i] == A[j].
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int bMax[26];
        int bTemp[26];
        memset(bMax, 0, sizeof(bMax));
        for (int i = 0; i < B.size(); ++i) {
            memset(bTemp, 0, sizeof(bTemp));
            count(bTemp, B[i]);
            for (int j = 0; j < 26; ++j)
                bMax[j] = max(bMax[j], bTemp[j]);
        }
        vector<string> res;
        for (int i = 0; i < A.size(); ++i) {
            memset(bTemp, 0, sizeof(bTemp));
            count(bTemp, A[i]);
            int j;
            for (j = 0; j < 26; ++j)
                if (bTemp[j] < bMax[j])
                    break;
            if (j == 26)
                res.push_back(A[i]);
        }
        return res;
    }
    
    void count(int* b, string& s) {
        for (auto& c : s)
            b[c - 'a']++;
    }
};
// @lc code=end

