class Solution {
public:
    bool verifyPostorder1(vector<int>& postorder) {
        if (postorder.size() == 0)
            return true;
        return check(0, postorder.size() - 1, postorder);
    }
    bool check(int left, int right, vector<int>& postorder) {
        if (left >= right)
            return true;
        int root = postorder[right];
        int split = -1;
        for (int i = left; i <= right; ++i) {
            if (postorder[i] >= root) {
                split = i;
                break;
            }
        }
        for (int i = split; i <= right; ++i) {
            if (postorder[i] < root)
                return false;
        }
        return check(left, split - 1, postorder) && check(split, right - 1, postorder);
    }
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> st;
        int n = postorder.size() - 1;
        int root = INT_MAX;
        for (int i = n; i >= 0; --i) {
            if (postorder[i] > root)
                return false;
            while (!st.empty() && st.top() > postorder[i]) {
                root = st.top();
                st.pop();
            }
            st.push(postorder[i]);
        }
        return true;
    }
};