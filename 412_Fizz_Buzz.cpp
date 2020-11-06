vector<string> fizzBuzz(int n) {
	vector<string> res(n);
	for (int i = 1 ; i <= n; ++i)
	{
		if (i % 3 == 0 && i % 5 == 0){
			res[i - 1] = "FizzBuzz";
		}
		else if (i  % 3 == 0){
			res[i - 1] = "Fizz";
		}
		else if (i % 5 == 0){
			res[i - 1] = "Buzz";
		}
		else{
		   res[i - 1] = toString(i);
		}
	}
	return res;
}
string toString(int n)
{
   string s;
   while (n){
	   int res = n % 10;
	   n = n / 10;
	   s.push_back('0' + res);
   }
   int start = 0, end = s.length() - 1;
   while (start < end){
	   swap(s[start], s[end]);
	   start++;
	   end--;
   }
   return s;
}

vector<string> fizzBuzz(int n) {
	vector<string> res(n);
	map<int, string> hash = {
		{3, "Fizz"},
		{5, "Buzz"},
	};
	
	for (int i = 1; i <= n; ++i){
		string s = "";
		for (auto pair: hash){
			if (i % pair.first == 0)
				s += pair.second;
		}
		if (s == ""){
			s += to_string(i);
		}
		res[i - 1] = s;
	}
	return res;
}