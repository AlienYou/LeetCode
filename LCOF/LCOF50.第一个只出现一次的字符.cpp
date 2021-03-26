class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> count(26, -2);
        for (int i = 0; i < s.length(); ++i) {
            if (count[s[i] - 'a'] == -2)
                count[s[i] - 'a'] = i;
            else
                count[s[i] - 'a'] = -1;
        }

        int first = s.length();
        for (int i = 0; i < 26; ++i) {
            if (count[i] >= 0 && count[i] < first)
                first = count[i];
        }
        return first == s.length() ? ' ' : s[first];
    }
};