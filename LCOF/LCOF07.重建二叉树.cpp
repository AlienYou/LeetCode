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