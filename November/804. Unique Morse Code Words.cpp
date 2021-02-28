int uniqueMorseRepresentations(vector<string>& words) {
	unordered_map<char, string> map = {
		{'a', ".-"},
		{'b', "-..."},
		{'c', "-.-."},
		{'d', "-.."},
		{'e', "."},
		{'f', "..-."},
		{'g', "--."},
		{'h', "...."},
		{'i', ".."},
		{'j', ".---"},
		{'k', "-.-"},
		{'l', ".-.."},
		{'m', "--"},
		{'n', "-."},
		{'o', "---"},
		{'p', ".--."},
		{'q', "--.-"},
		{'r', ".-."},
		{'s', "..."},
		{'t', "-"},
		{'u', "..-"},
		{'v', "...-"},
		{'w', ".--"},
		{'x', "-..-"},
		{'y', "-.--"},
		{'z', "--.."}
	};
	int size = words.size();
	unordered_set<string> strSet;
	
	for (int i = 0; i < size; ++i){
		int length = words[i].size();
		string s;
		for (int j = 0; j < length; ++j){
			s += map[words[i][j]];
		}
		strSet.insert(s);
	}
	
	return strSet.size();
}