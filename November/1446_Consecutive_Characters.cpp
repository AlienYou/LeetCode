int maxPower(string s) {
	int res = 0;
	int start = 0, end = 0;
	int length = s.length();
	while (end < length)
	{
		if (s[start] != s[end])
		{
			res = max(res, end - start);
			start = end;
		}
		end++;
	}
	return s[start] == s[end - 1]? max(res, end - start) : res;
}