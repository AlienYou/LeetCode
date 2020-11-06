int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	unordered_map<int, int> map;
	int size = A.size();
	vector<int> sum(size * size);
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			sum[i * size + j] = A[i] + B[j];
		}
	}
	
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			map[C[i] + D[j]]++;
		}
	}
	int result = 0;
	for (int i = 0; i < sum.size(); ++i)
	{
		result += map[-sum[i]];
	}
	return result;
}