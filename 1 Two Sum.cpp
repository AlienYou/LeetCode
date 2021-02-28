vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> map;
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i){
		if (map.count(target - nums[i])){
			res.push_back(map[target - nums[i]]);
			res.push_back(i);
		}
		map[nums[i]] = i;
	}
	return res;
}