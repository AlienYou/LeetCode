class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return false;
        int left = 0, right = 0;
        unordered_map<char, int> countMap;
        int res = 0;
        while (right < s.length()) {
            if (countMap.count(s[right]) && countMap[s[right]] >= left) {
                left = countMap[s[right]] + 1;
            }
            res = max(res, right - left + 1);
            countMap[s[right]] = right;
            ++right;
        }
        return res;
    }
    int lengthOfLongestSubstring1(string s) {
        if (s.length() == 0)
            return false;
        int left = 0, right = 0;
        unordered_map<char, int> countMap;
        int res = 0;
        while (right < s.length()) {
            countMap[s[right]]++;
            while (!isOneCount(countMap)) {
                countMap[s[left]]--;
                ++left;
            }
            res = max(res, right - left + 1);
            ++right;
        }
        return res;
    }
    bool isOneCount(unordered_map<char, int>& countMap) {
        for (const auto& ele : countMap) 
            if (ele.second > 1)
                return false;
        return true;
    }
};