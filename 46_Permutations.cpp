vector<vector<int>> res;
void core(vector<int>& nums, int left){
	if (left == nums.size()){
		res.push_back(nums);
		return;
	}
	for (int i = left; i < nums.size(); ++i){
		swap(nums[left], nums[i]);
		core(nums, left + 1);
		swap(nums[left], nums[i]);
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	core(nums, 0);
	return res;
}