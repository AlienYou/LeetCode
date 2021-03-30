class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r && s[l] == ' ') ++l;
        while (l < r && s[r] == ' ') --r;
        string res;
        for (int i = l; i <= r; ++i) {
            if (s[i] == ' ')
                continue;
            int right = i;
            while (right <= r && s[right] != ' ')
                right++;
            int low = i, high = right - 1;
            while (low <= high) {
                res.push_back(s[high--]);
            }
            if (right < r)
                res.push_back(s[right]);
            i = right;    
        }
        int left = 0, right = res.length() - 1;
        while (left < right) 
            swap(res[left++], res[right--]);
        return res;
    }
};