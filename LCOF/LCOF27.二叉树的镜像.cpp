class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};