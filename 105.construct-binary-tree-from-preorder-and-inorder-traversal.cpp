/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (51.05%)
 * Likes:    4711
 * Dislikes: 122
 * Total Accepted:    457.6K
 * Total Submissions: 885.9K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int left = 0, right = preorder.size() - 1;
        return construct(preorder, left, right, inorder, left, right);
    }
    
    TreeNode* construct(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight) {
        if (preLeft > preRight || inLeft > inRight)
            return nullptr;
        int rootVal = preorder[preLeft];
        TreeNode* curNode = new TreeNode(rootVal);
        
        int splitIndex = -1;
        for (int i = inLeft; i <= inRight; ++i) {
            if (inorder[i] == rootVal) {
                splitIndex = i;
                break;
            }
        }
        int preLeftTree = preLeft + splitIndex - inLeft;
        curNode->left = construct(preorder, preLeft + 1, preLeftTree, inorder, inLeft, splitIndex - 1);
        curNode->right = construct(preorder, preLeftTree + 1, preRight, inorder, splitIndex + 1, inRight);
        return curNode;
    }
};
// @lc code=end

