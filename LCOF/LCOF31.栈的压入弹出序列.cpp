class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int ind = 0;
        stack<int> st;
        for (int i = 0; i < pushed.size(); ++i) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[ind]) {
                st.pop();
                ++ind;
            }
        }
        return st.empty();
    }
};