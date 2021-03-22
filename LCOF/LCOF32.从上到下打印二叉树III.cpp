class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        bool leftToRight = true;
        while (!que.empty()) {
            int size = que.size();
            vector<int> level(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                int ind = leftToRight ? i : size - i - 1;
                level[ind] = node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            leftToRight = !leftToRight;
            if (size)
                res.push_back(level);
        }
        return res;
    }
};