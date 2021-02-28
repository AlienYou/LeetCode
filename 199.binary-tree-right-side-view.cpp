/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (55.60%)
 * Likes:    3317
 * Dislikes: 178
 * Total Accepted:    385.5K
 * Total Submissions: 688.5K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    vector<int> rightSideView1(TreeNode* root) {
        if (!root)
            return vector<int>();
        queue<TreeNode*> que;
        que.push(root);
        vector<int> result;
        while (!que.empty()) {
            int size = que.size();
            int last = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                last = node->val;
                que.pop();
                if (node->left) 
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            if (size)
                result.push_back(last);
        }
        return result;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        core(root, 1);
        return res;
    }
    void core(TreeNode* root, int level) {
        if (!root)
            return;
        if (level > this->res.size())
            this->res.push_back(root->val);
        else
            this->res[level - 1] = root->val;
        core(root->left, level + 1);
        core(root->right, level + 1);
    }
private:
    vector<int> res;
};
// @lc code=end

