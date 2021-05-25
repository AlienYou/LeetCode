/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
 *
 * https://leetcode.com/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (38.42%)
 * Likes:    1741
 * Dislikes: 27
 * Total Accepted:    46K
 * Total Submissions: 113.8K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * You are given the root of a binary tree. We install cameras on the tree
 * nodes where each camera at a node can monitor its parent, itself, and its
 * immediate children.
 * 
 * Return the minimum number of cameras needed to monitor all nodes of the
 * tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [0,0,null,0,0]
 * Output: 1
 * Explanation: One camera is enough to monitor all nodes if placed as shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [0,0,null,0,null,0,null,null,0]
 * Output: 2
 * Explanation: At least two cameras are needed to monitor all nodes of the
 * tree. The above image shows one of the valid configurations of camera
 * placement.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * Node.val == 0
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
struct Status {
    int st1;
    int st2;
    int st3;
    Status() : st1(0), st2(0), st3(9999) { }
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        Status ans;
        ans = solve(root);
        return min(ans.st2, ans.st3);
    }
    
    Status solve(TreeNode* root) {
        if (root == nullptr)
            return Status();
        Status L = solve(root->left);
        Status R = solve(root->right);
        Status cur;
        int LMin = min(L.st2, L.st3);
        int RMin = min(R.st2, R.st3);
        cur.st1 = L.st2 + R.st2;
        cur.st2 = min(L.st3 + RMin, R.st3 + LMin);
        cur.st3 = 1 + min(L.st1, LMin) + min(R.st1, RMin);
        return cur;
    }
};
// @lc code=end

