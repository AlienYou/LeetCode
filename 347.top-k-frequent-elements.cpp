/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (62.13%)
 * Likes:    4609
 * Dislikes: 261
 * Total Accepted:    554.2K
 * Total Submissions: 887.4K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * It's guaranteed that the answer is unique, in other words the set of the top
 * k frequent elements is unique.
 * You can return the answer in any order.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        if (k == 0)
            return vector<int>();
        unordered_map<int, int> mapCount;
        vector<int> res;
        vector<vector<int>> count(nums.size() + 1, vector<int>());
        for (const auto& ele : nums) {
            mapCount[ele]++;
        }
        for (const auto& ele : mapCount) {
            count[ele.second].push_back(ele.first);
        }
        for (int i = nums.size(); i >= 0; --i) {
             for (int j = 0; j < count[i].size(); ++j) {
                res.push_back(count[i][j]);
                --k;
                 if (k == 0)
                     return res;
             }
        }
        return res;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size())
            return nums;
        unordered_map<int, int> count_map;
        for (const auto& ele : nums) 
            count_map[ele] += 1;
        auto comp = [&count_map](int n1, int n2) { return count_map[n1] > count_map[n2];};
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        for (const auto& ele : count_map) {
            heap.push(ele.first);
            if (heap.size() > k)
                heap.pop();
        }
        vector<int> top(k);
        for (int i = 0; i < k; ++i) {
            top[i] = heap.top();
            heap.pop();
        }
        return top;
    }
};
// @lc code=end

