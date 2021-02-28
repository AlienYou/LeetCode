/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 *
 * https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
 *
 * algorithms
 * Easy (69.66%)
 * Likes:    564
 * Dislikes: 38
 * Total Accepted:    46.7K
 * Total Submissions: 65.9K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]\n3'
 *
 * Given a m * n matrix mat of ones (representing soldiers) and zeros
 * (representing civilians), return the indexes of the k weakest rows in the
 * matrix ordered from the weakest to the strongest.
 * 
 * A row i is weaker than row j, if the number of soldiers in row i is less
 * than the number of soldiers in row j, or they have the same number of
 * soldiers but i is less than j. Soldiers are always stand in the frontier of
 * a row, that is, always ones may appear first and then zeros.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = 
 * [[1,1,0,0,0],
 * ⁠[1,1,1,1,0],
 * ⁠[1,0,0,0,0],
 * ⁠[1,1,0,0,0],
 * ⁠[1,1,1,1,1]], 
 * k = 3
 * Output: [2,0,3]
 * Explanation: 
 * The number of soldiers for each row is: 
 * row 0 -> 2 
 * row 1 -> 4 
 * row 2 -> 1 
 * row 3 -> 2 
 * row 4 -> 5 
 * Rows ordered from the weakest to the strongest are [2,0,3,1,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = 
 * [[1,0,0,0],
 * [1,1,1,1],
 * [1,0,0,0],
 * [1,0,0,0]], 
 * k = 2
 * Output: [0,2]
 * Explanation: 
 * The number of soldiers for each row is: 
 * row 0 -> 1 
 * row 1 -> 4 
 * row 2 -> 1 
 * row 3 -> 1 
 * Rows ordered from the weakest to the strongest are [0,2,3,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 2 <= n, m <= 100
 * 1 <= k <= m
 * matrix[i][j] is either 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        if (mat.size() == 0)
            return vector<int>();
        vector<int> result;
        vector<pair<int, int>> vecRow;
        for (int i = 0; i < mat.size(); ++i) {
            int index = binarySearch(mat[i]);
            vecRow.push_back(make_pair(index + 1, i));
        }
        
        sort(vecRow.begin(), vecRow.end());
        for (int i = 0; i < k; ++i) {
            result.push_back(vecRow[i].second);
        }
        return result;
    }
    int binarySearch(vector<int>& v) {
        int left = 0, right = v.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (v[mid] == 0) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return v[left] == 1 ? left : -1;
    }
};
// @lc code=end

