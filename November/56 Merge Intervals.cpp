vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> res;
	auto function = [](vector<int>& a, vector<int>& b){ return a[0] < b[0]; };
	sort(intervals.begin(), intervals.end(), function);
	int index = 0, size = intervals.size();
	while (index < size)
	{
		int start = intervals[index][0];
		int end = intervals[index][1];
		while (index < size - 1 && end >= intervals[index + 1][0])
			end = max(intervals[++index][1], end);
		res.push_back({start, end});
		index++;
	}
	return res;
}