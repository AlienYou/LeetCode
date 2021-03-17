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
    TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
        int preSize = preorder.size();
        int inSize = inorder.size();
        return core(preorder, 0, preSize - 1, inorder, 0, inSize - 1);
    }

    TreeNode* core(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight) {
        if (preLeft > preRight || inLeft > inRight)
            return nullptr;
        int rootVal = preorder[preLeft];
        int splitInd;
        for (splitInd = inLeft; splitInd <= inRight; ++splitInd) {
            if (inorder[splitInd] == rootVal)
                break;
        }
        int preLeftTree = preLeft + splitInd - inLeft;
        TreeNode* root = new TreeNode(rootVal);
        root->left = core(preorder, preLeft + 1, preLeftTree, inorder, inLeft, splitInd - 1);
        root->right = core(preorder, preLeftTree + 1, preRight, inorder, splitInd + 1, inRight);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size())
            return nullptr;
        stack<TreeNode*> st;
        int inorderIndex = 0;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode* node = st.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                st.push(node->left);
            } else {
                while (!st.empty() && st.top()->val == inorder[inorderIndex]) {
                    node = st.top();
                    st.pop();
                    inorderIndex++;
                }
                node->right = new TreeNode(preorderVal);
                st.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end

