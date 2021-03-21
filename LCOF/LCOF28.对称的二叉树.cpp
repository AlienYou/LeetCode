class Solution {
public:
    bool isSymmetric1(TreeNode* root) {
        if (root == nullptr)
            return true;
        return core(root->left, root->right);
    }
    bool core(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return core(left->left, right->right) && core(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        que.push(root);
        while (!que.empty()) {
            TreeNode* node1 = que.front();
            que.pop();
            TreeNode* node2 = que.front();
            que.pop();
            if (node1 == nullptr && node2 == nullptr)
                continue;
            if (node1 == nullptr || node2 == nullptr || node1->val != node2->val)
                return false;
            que.push(node1->left);
            que.push(node2->right);
            que.push(node1->right);
            que.push(node2->left);
        }
        return true;
    }
};