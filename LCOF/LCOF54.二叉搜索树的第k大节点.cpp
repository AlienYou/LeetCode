class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (!st.empty() || root) {
            if (root != nullptr) {
                st.push(root);
                root = root->right;
            } else {
                root = st.top();
                st.pop();
                k--;
                if (k == 0)
                    return root->val;
                root = root->left;
            }
        }
        return 0;
    }
};