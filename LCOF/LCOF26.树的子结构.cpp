class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
            return false;
        return isSame(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool isSame(TreeNode* A, TreeNode* B) {
        if (B == nullptr)
            return true;
        if (A == nullptr || A->val != B->val)
            return false;
        return isSame(A->left, B->left) && isSame(A->right, B->right);
    }
};