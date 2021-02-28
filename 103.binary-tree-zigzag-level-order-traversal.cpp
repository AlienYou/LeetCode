/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (49.67%)
 * Likes:    3088
 * Dislikes: 122
 * Total Accepted:    474.1K
 * Total Submissions: 947.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> nodeQue;
        nodeQue.push(root);
        bool leftToRight = true;
        while (!nodeQue.empty()) {
            int size = nodeQue.size();
            vector<int> curLevel(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = nodeQue.front();
                nodeQue.pop();
                int index = leftToRight? i : size - i - 1;
                curLevel[index] = node->val;
                if (node->left)
                    nodeQue.push(node->left);
                if (node->right)
                    nodeQue.push(node->right);
            }
            leftToRight = !leftToRight;
            if (size) 
                result.push_back(curLevel);
        }
        return result;
    }
};
// @lc code=end

