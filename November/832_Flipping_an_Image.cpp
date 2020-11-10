vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	int size = A[0].size();
	for (auto &arr: A){
		for (int i = 0; i < ((size + 1) >> 1); ++i){
			int temp = arr[i] ^ 1;
			arr[i] = arr[size - 1 - i] ^ 1;
			arr[size - 1 - i] = temp;
		}
	}
	return A;
}