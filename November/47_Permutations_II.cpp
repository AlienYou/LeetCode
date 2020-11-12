void backtrack(vector<vector<int>>& res, int size, vector<int>& comp, unordered_map<int, int>& map)
{
	if (comp.size() == size){
		res.push_back(comp);
		return;
	}
	for (auto& ele: map){
		if (ele.second == 0)
			continue;
		ele.second--;
		comp.push_back(ele.first);
		backtrack(res, size, comp, map);
		comp.pop_back();
		ele.second++;
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> res;
	unordered_map<int, int> map;
	for (auto& i : nums){
		map[i]++;
	}
	vector<int> comp;
	backtrack(res, nums.size(), comp, map);
	return res;
}