class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> pareMap;
        stack<TreeNode*> st;
        st.push(root);
        pareMap[root] = nullptr;
        while (!st.empty()) {
            TreeNode* pare = st.top();
            st.pop();
            if (pare->left) {
                st.push(pare->left);
                pareMap[pare->left] = pare;
            } 
            if (pare->right) {
                st.push(pare->right);
                pareMap[pare->right] = pare;
            }
        }

        unordered_set<TreeNode*> pathSet;
        while (p != nullptr) {
            pathSet.insert(p);
            p = pareMap[p];
        }
        while (!pathSet.count(q)) {
            q = pareMap[q];
        }
        return q;
    }
};