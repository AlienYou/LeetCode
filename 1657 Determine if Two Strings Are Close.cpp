bool closeStrings(string word1, string word2) {
	int countMap1[26] ={0};
	int countMap2[26] = {0};
	for (int i = 0; i < word1.length(); ++i){
		countMap1[word1[i] - 'a']++;
	} 
	for (int i = 0; i < word2.length(); ++i){
		countMap2[word2[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i){
		if (countMap1[i] == 0 && countMap2[i] == 0)
			continue;
		if (countMap1[i] == 0 || countMap2[i] == 0)
			return false;
	}
	sort(begin(countMap1), end(countMap1));
	sort(begin(countMap2), end(countMap2));
	for (int i = 0; i < 26; ++i){
		if (countMap1[i] != countMap2[i])
			return false;
	}
	return true;
}