int minCostToMoveChips(vector<int>& position) {
	int odd_cnt = 0;
	int even_cnt = 0;
	for (int& ele : position)
	{
		if (ele % 2 == 0)
			odd_cnt++;
		else
			even_cnt++;
	}
	return min(odd_cnt, even_cnt);
}