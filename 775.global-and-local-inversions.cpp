/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 *
 * https://leetcode.com/problems/global-and-local-inversions/description/
 *
 * algorithms
 * Medium (42.42%)
 * Likes:    702
 * Dislikes: 242
 * Total Accepted:    40.8K
 * Total Submissions: 89.5K
 * Testcase Example:  '[0]'
 *
 * We have some permutation A of [0, 1, ..., N - 1], where N is the length of
 * A.
 * 
 * The number of (global) inversions is the number of i < j with 0 <= i < j < N
 * and A[i] > A[j].
 * 
 * The number of local inversions is the number of i with 0 <= i < N and A[i] >
 * A[i+1].
 * 
 * Return true if and only if the number of global inversions is equal to the
 * number of local inversions.
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,0,2]
 * Output: true
 * Explanation: There is 1 global inversion, and 1 local inversion.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [1,2,0]
 * Output: false
 * Explanation: There are 2 global inversions, and 1 local inversion.
 * 
 * 
 * Note:
 * 
 * 
 * A will be a permutation of [0, 1, ..., A.length - 1].
 * A will have length in range [1, 5000].
 * The time limit for this problem has been reduced.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int localCount = 0;
        vector<int> B(A.size());
        int inverseCount = 0;
        for (int i = 0; i < A.size() - 1; ++i) {
            if (A[i] > A[i + 1])
                ++localCount;
        }
        
        inverse(A, B, 0, A.size() - 1, inverseCount);
        //cout << inverseCount << endl;
        return localCount == inverseCount;
    }

    int combine(vector<int>& A, vector<int>& B, int left, int mid, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
             B[i] = A[i];
        }
        int l = left, r = mid + 1;
        for (int i = left; i <= right; ++i) {
            if (l > mid)
                A[i] = B[r++];
            else if (r > right) {
                A[i] = B[l++];
                count += r - mid - 1;
            } else if (B[l] > B[r]) {
                A[i] = B[r++];
            } else {
                A[i] = B[l++];
                count += r - mid - 1;
            }
        }
        return count;
    }
    
    void inverse(vector<int>& A, vector<int>& B, int left, int right, int& inverseCount) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        inverse(A, B, left, mid, inverseCount);
        inverse(A, B, mid + 1, right, inverseCount);
        inverseCount += combine(A, B, left, mid, right); 
    }
};
// @lc code=end

