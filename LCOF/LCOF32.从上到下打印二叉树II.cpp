class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vlevel(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                vlevel[i] = node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            res.push_back(vlevel);
        }
        return res;
    }
};