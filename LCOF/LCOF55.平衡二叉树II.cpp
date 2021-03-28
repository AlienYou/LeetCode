class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) == -1 ? false : true;
    }
    int depth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = depth(root->left);
        if (left == -1) return -1;
        int right = depth(root->right);
        if (right == -1) return -1;
        return abs(right - left) > 1 ? -1 : max(right, left) + 1;
    }
};