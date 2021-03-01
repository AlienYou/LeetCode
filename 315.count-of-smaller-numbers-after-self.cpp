/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (42.51%)
 * Likes:    3209
 * Dislikes: 101
 * Total Accepted:    161.4K
 * Total Submissions: 379.9K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1]
 * Output: [0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [-1,-1]
 * Output: [0,0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> c;
    vector<int> a;
    
    void init(int length) {
        c.resize(length, 0);
    }
    
    int lowBit(int x) {
        return x & (-x);
    }
    
    void update(int pos) {
        while (pos < c.size()) {
            c[pos] += 1;
            pos += lowBit(pos);
        }
    }
    
    int query(int pos) {
        int ret = 0;
        
        while (pos > 0) {
            ret += c[pos];
            pos -= lowBit(pos);
        }
        return ret;
    }
    
    void discretization(vector<int>& nums) {
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }
    
    int getId(int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }
    
    vector<int> countSmaller1(vector<int>& nums) {
        vector<int> resultList;
        discretization(nums);
        
        init(nums.size() + 5);
        
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            int id = getId(nums[i]);
            resultList.push_back(query(id - 1));
            update(id);
        }
        reverse(resultList.begin(), resultList.end());
        return resultList;
    }
    
    void merge(vector<int>& nums, int l, int mid, int r) {
        int i = l, j = mid + 1, p = l;
        
        while (i <= mid || j <= r) {
            if (j > r || (i <= mid && nums[index[i]] <= nums[index[j]])) {
                tempIndices[p] = index[i];
                count[tempIndices[p]] += j - mid - 1;
                ++i;
            } else {
                tempIndices[p] = index[j];
                ++j;
            }
            ++p;
        }
        copy(tempIndices.begin() + l, tempIndices.begin() + r + 1, index.begin() + l);
    }
    
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    
    vector<int> index;
    vector<int> tempIndices;
    vector<int> count;
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        index.resize(n, 0);
        tempIndices.resize(n, 0);
        count.resize(n, 0);
        iota(index.begin(), index.end(), 0);
        mergeSort(nums, 0, n - 1);
        return count;
    }
};
// @lc code=end

