int core(TreeNode* root, int& sum){
	if (root == nullptr)
		return 0;
	int leftAbsDiff = core(root->left, sum);
	int rightAbsDiff = core(root->right, sum);
	
	sum += abs(rightAbsDiff - leftAbsDiff);
	
	return leftAbsDiff + rightAbsDiff + root->val;
}

int findTilt(TreeNode* root) {
	int sum = 0;
	core(root, sum);
	return sum;
}