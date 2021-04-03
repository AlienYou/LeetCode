/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (48.50%)
 * Likes:    2654
 * Dislikes: 85
 * Total Accepted:    404.2K
 * Total Submissions: 817.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given the root of a binary tree and an integer targetSum, return all
 * root-to-leaf paths where each path's sum equals targetSum.
 * 
 * A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: [[5,4,11,2],[5,8,4,5]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3], targetSum = 5
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1,2], targetSum = 0
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> sumMap;
        sumMap[0] = 1;
        return DFS(root, 0, sum, 0, sumMap);
    }
    
    int DFS(TreeNode* root, int level, int sum, int curSum, unordered_map<int, int>& sumMap) {
        if (root == nullptr)
            return 0;
        
        curSum += root->val;
        int ans = 0;
        if (sumMap.count(curSum - sum))
            ans += sumMap[curSum - sum];
        sumMap[curSum]++;
        ans += DFS(root->left, level + 1, sum, curSum, sumMap);
        ans += DFS(root->right, level + 1, sum, curSum, sumMap);
        sumMap[curSum]--;
        return ans;
    }
};
// @lc code=end

