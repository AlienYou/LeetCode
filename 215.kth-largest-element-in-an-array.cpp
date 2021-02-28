/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (57.38%)
 * Likes:    5097
 * Dislikes: 331
 * Total Accepted:    823.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

// @lc code=start
class Solution {
public:
    int getRandomIndex(int left, int right) {
        return random() % (right - left + 1) + left;
    }
    
    int core(vector<int>& nums, int left, int right) {
        int index = getRandomIndex(left, right);
        swap(nums[index], nums[right]);
        int sortIndex = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] >= nums[right]) {
                if (i != sortIndex) {
                    swap(nums[i], nums[sortIndex]);
                }
                sortIndex++;
            }
        }
        swap(nums[sortIndex], nums[right]);
        return sortIndex;
    }

    
    int findKthLargest1(vector<int>& nums, int k) {
        int index = -1;
        int left = 0, right = nums.size() - 1;
        while (index + 1 != k) {
            index = core(nums, left, right);
            if (index + 1 > k)
                right = index - 1;
            else if (index + 1 < k) {
                left = index + 1;
            }
        }
        return nums[index];
    }
    
    
    void buildHeap(vector<int>& nums) {
        int size = nums.size();
        for (int i = size / 2 - 1; i >= 0; --i) {
            buildMaxHeap(nums, i, size);
        }
    }
    
    void buildMaxHeap(vector<int>& nums, int i, int size) {
        int left = 2 * i + 1, right = 2 * i + 2;
        int largest = i;
        if (left < size && nums[largest] < nums[left]) 
            largest = left;
        if (right < size && nums[largest] < nums[right])
            largest = right;
        if (i != largest) {
            swap(nums[i], nums[largest]);
            buildMaxHeap(nums, largest, size);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        buildHeap(nums);
        int size = nums.size();
        for (int i = size - 1; i > nums.size() - k; --i) {
            swap(nums[0], nums[i]);
            size--;
            buildMaxHeap(nums, 0, size);
        }
        return nums[0];
    }
    
    void f(vector<int>& nums) {
        for (auto& ele : nums)
            cout << ele << " ";
        cout << endl;
    }
};
// @lc code=end

