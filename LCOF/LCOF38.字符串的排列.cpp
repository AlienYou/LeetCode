class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        permutate(s, 0, s.length(), res);
        return res;
    }
    void permutate(string& s, int ind, int L, vector<string>& res) {
        if (ind == L) {
            res.push_back(s);
            return;
        }
        unordered_set<char> charSet;
        for (int i = ind; i < L; ++i) {
            if (charSet.count(s[i]))
                continue;
            charSet.insert(s[i]);
            swap(s[ind], s[i]);
            permutate(s, ind + 1, L, res);
            swap(s[ind], s[i]);
        }
    }
};