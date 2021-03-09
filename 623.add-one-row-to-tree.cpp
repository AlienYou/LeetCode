/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
 *
 * https://leetcode.com/problems/add-one-row-to-tree/description/
 *
 * algorithms
 * Medium (50.23%)
 * Likes:    682
 * Dislikes: 148
 * Total Accepted:    51.3K
 * Total Submissions: 99.3K
 * Testcase Example:  '[4,2,6,3,1,5]\n1\n2'
 *
 * Given the root of a binary tree, then value v and depth d, you need to add a
 * row of nodes with value v at the given depth d. The root node is at depth
 * 1. 
 * 
 * The adding rule is: given a positive integer depth d, for each NOT null tree
 * nodes N in depth d-1, create two tree nodes with value v as N's left subtree
 * root and right subtree root. And N's original left subtree should be the
 * left subtree of the new left subtree root, its original right subtree should
 * be the right subtree of the new right subtree root. If depth d is 1 that
 * means there is no depth d-1 at all, then create a tree node with value v as
 * the new root of the whole original tree, and the original tree is the new
 * root's left subtree.
 * 
 * Example 1:
 * 
 * Input: 
 * A binary tree as following:
 * ⁠      4
 * ⁠    /   \
 * ⁠   2     6
 * ⁠  / \   / 
 * ⁠ 3   1 5   
 * 
 * v = 1
 * 
 * d = 2
 * 
 * Output: 
 * ⁠      4
 * ⁠     / \
 * ⁠    1   1
 * ⁠   /     \
 * ⁠  2       6
 * ⁠ / \     / 
 * ⁠3   1   5   
 * 
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * A binary tree as following:
 * ⁠     4
 * ⁠    /   
 * ⁠   2    
 * ⁠  / \   
 * ⁠ 3   1    
 * 
 * v = 1
 * 
 * d = 3
 * 
 * Output: 
 * ⁠     4
 * ⁠    /   
 * ⁠   2
 * ⁠  / \    
 * ⁠ 1   1
 * ⁠/     \  
 * 3       1
 * 
 * 
 * 
 * Note:
 * 
 * The given d is in range [1, maximum depth of the given tree + 1].
 * The given binary tree has at least one tree node.
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
    TreeNode* addOneRow1(TreeNode* root, int v, int d, int curd = 1) {
        if (root == nullptr)
            return root;
        if (d == 1) 
            return root = new TreeNode(v, root, nullptr);
        if (curd == d - 1) {
            TreeNode* left = new TreeNode(v, root->left, nullptr);
            TreeNode* right = new TreeNode(v, nullptr, root->right);
            root->left = left;
            root->right = right;
        } else {
            addOneRow(root->left, v, d, curd + 1);
            addOneRow(root->right, v, d, curd + 1);
        }
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            return root = new TreeNode(v, root, nullptr);
        }
        queue<TreeNode*> que;
        que.push(root);
        int curD = 1;
        while (curD < d - 1) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            ++curD;
        }
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            TreeNode* newLeft = new TreeNode(v, cur->left, nullptr);
            TreeNode* newRight = new TreeNode(v, nullptr, cur->right);
            cur->left = newLeft;
            cur->right = newRight;
        }
        return root;
    }
};
// @lc code=end

