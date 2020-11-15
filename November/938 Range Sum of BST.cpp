int rangeSumBST(TreeNode* root, int low, int high) {
	if (root == nullptr)
		return 0;
	int res = 0;
	if (root->val >= low && root->val <= high)
		res = root->val;
	if (root->val > low)
		res += rangeSumBST(root->left, low, high);
	if (root->val < high)
		res += rangeSumBST(root->right, low, high);
	return res;
}