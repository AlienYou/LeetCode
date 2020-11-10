int result = 0;

void core(TreeNode* root, int maxValue, int minValue){
	if (root == nullptr)
		return;
	maxValue = max(maxValue, root->val);
	minValue = min(minValue, root->val);
	result = max(abs(maxValue - minValue), result);
	core(root->left, maxValue, minValue);
	core(root->right, maxValue, minValue);
}

 int helper(TreeNode* root, int maxValue, int minValue){
	if (root == nullptr)
		return maxValue - minValue;
	maxValue = max(maxValue, root->val);
	minValue = min(minValue, root->val);
	int left = helper(root->left, maxValue, minValue);
	int right = helper(root->right, maxValue, minValue);
	return max(left, right);
}

int maxAncestorDiff(TreeNode* root) {
	core(root, root->val, root->val);
	return result;
}