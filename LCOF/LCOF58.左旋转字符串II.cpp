class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int L = s.length() - 1;
        reverse(s, 0, n - 1);
        reverse(s, n, L);
        reverse(s, 0, L);
        return s;
    }

    void reverse(string& s, int left, int right) {
        if (left >= right)  return;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};