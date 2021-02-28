/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 *
 * https://leetcode.com/problems/flatten-nested-list-iterator/description/
 *
 * algorithms
 * Medium (54.10%)
 * Likes:    2030
 * Dislikes: 775
 * Total Accepted:    201.9K
 * Total Submissions: 370.2K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 * 
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [[1,1],2,[1,1]]
 * Output: [1,1,2,1,1]
 * Explanation: By calling next repeatedly until hasNext returns
 * false, 
 * the order of elements returned by next should be: [1,1,2,1,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,[4,[6]]]
 * Output: [1,4,6]
 * Explanation: By calling next repeatedly until hasNext returns
 * false, 
 * the order of elements returned by next should be: [1,4,6].
 * 
 * 
 * 
 * 
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        current = 0;
        helper(nestedList);
    }
    /*
    NestedIterator(vector<NestedInteger> &nestedList) {
        current = 0;
        flatten(nestedList);
    }*/
    
    int next() {
        if (this->hasNext()) {
            return list[current++];
        }
        return -1;
    }
    
    bool hasNext() {
        return !(current == list.size());
    }
private:
    void helper(vector<NestedInteger>& nestedList) {
        stack<NestedInteger> st;
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            st.push(nestedList[i]);
        }
        
        while (!st.empty()) {
            auto cur = st.top();
            st.pop();
            if (cur.isInteger()) {
                list.push_back(cur.getInteger());
            } else {
                auto intList = cur.getList();
                for (int i = intList.size() - 1; i >= 0; --i) {
                    st.push(intList[i]);
                }
            }
        }
    }
    
    void flatten(vector<NestedInteger>& nestedList) {
        int n = nestedList.size();
        for (int i = 0; i < n; ++i) {
            if (nestedList[i].isInteger()) {
                list.push_back(nestedList[i].getInteger());
            } else {
                flatten(nestedList[i].getList());
            }
        }
    }     
private:
    int current;
    vector<int> list;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

