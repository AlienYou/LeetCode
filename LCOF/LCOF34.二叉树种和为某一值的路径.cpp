class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> pareMap;
    vector<vector<int>> res;

    void getPath(TreeNode* p) {
        vector<int> cur;
        while (p != nullptr) {
            cur.push_back(p->val);
            p = pareMap[p];
        }
        reverse(cur.begin(), cur.end());
        res.push_back(cur);
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (root == nullptr)
            return res;
        queue<TreeNode*> que;
        queue<int> queSum;
        pareMap[root] = nullptr;
        que.push(root);
        queSum.push(0);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            int sum = queSum.front() + node->val;
            queSum.pop();
            if (node->left == nullptr && node->right == nullptr) {
                if (sum == target) {
                    getPath(node);
                }
            }
            if (node->left) {
                pareMap[node->left] = node;
                que.push(node->left);
                queSum.push(sum);
            }
            if (node->right) {
                pareMap[node->right] = node;
                que.push(node->right);
                queSum.push(sum);
            } 
        }
        return res;
    }
};