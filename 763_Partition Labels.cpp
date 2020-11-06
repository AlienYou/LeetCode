vector<int> partitionLabels(string S) {
	vector<int> charMap(26);
	int length = S.length();
	for (int i = 0; i < length; ++i){
		charMap[S[i] - 'a'] = i;
	}
	vector<int> ans;
	int anchor = 0, j = 0;
	for (int i = 0; i < length; ++i){
		j = max(charMap[S[i] - 'a'], j);
		if (j == i)
		{
			ans.push_back(j - anchor + 1);
			anchor = j + 1;
		}
	}
	return ans;
}