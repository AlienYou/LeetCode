/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (64.40%)
 * Likes:    1713
 * Dislikes: 182
 * Total Accepted:    160.2K
 * Total Submissions: 246.7K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 * 
 * Example 1:
 * 
 * Input:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 * 
 * 
 * 
 * Note:
 * 
 * The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels1(TreeNode* root) {
        vector<double> result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            double val = 0;
            int size = que.size();
            for (int i = 0; i < size; ++i){
                TreeNode* node = que.front();
                que.pop();
                val += node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            result.push_back(val / size);
        } 
        return result;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<int> count;
        dfs(root, 1, result, count);
        for (int i = 0; i < result.size(); ++i) {
            result[i] = result[i] / count[i];
        }
        return result;
    }
    void dfs(TreeNode* root, int depth, vector<double>& result, vector<int>& count) {
        if (root == nullptr)
            return;
        if (result.size() < depth) {
            result.push_back(root->val);
            count.push_back(1);
        } else {
            result[depth - 1] += root->val;
            count[depth - 1] += 1;
        }
        dfs(root->left, depth + 1, result, count);
        dfs(root->right, depth + 1, result, count);
    }
};
// @lc code=end

