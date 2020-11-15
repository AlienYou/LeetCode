int core(string& s, int start, int end, int k){
	if (end < k)
		return 0;
	int countMap[26] = {0};
	for (int i = start; i < end; i++){
		countMap[s[i] - 'a']++;
	}
	for (int i = start; i < end; ++i){
		if (countMap[s[i] - 'a'] >= k)
			continue;
		int margin = i + 1;
		return max(core(s, start, i, k), core(s, margin, end, k));
	}
	return end - start;
}
int longestSubstring(string s, int k) {
	int n = s.length();
	return core(s, 0, n, k);
}