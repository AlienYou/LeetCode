int longestMountain(vector<int>& A) {
	if (A.size() <= 2)
	   return 0; 
	int res = 0;
	for (int i = 1; i < A.size() - 1; ++i){
		if (A[i] > A[i - 1] && A[i] > A[i + 1])
		{
			int l = i - 1;
			int h = i + 1;
			while (l > 0 && A[l] > A[l - 1]) l--;
			while (h < A.size() - 1 && A[h] > A[h + 1]) h++;
			res = max(res, h - l + 1);
		}
	}
	return res;
}