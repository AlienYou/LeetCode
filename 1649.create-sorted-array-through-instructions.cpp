#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=1649 lang=cpp
 *
 * [1649] Create Sorted Array through Instructions
 *
 * https://leetcode.com/problems/create-sorted-array-through-instructions/description/
 *
 * algorithms
 * Hard (42.52%)
 * Likes:    303
 * Dislikes: 50
 * Total Accepted:    15.5K
 * Total Submissions: 42.5K
 * Testcase Example:  '[1,5,6,2]'
 *
 * Given an integer array instructions, you are asked to create a sorted array
 * from the elements in instructions. You start with an empty container nums.
 * For each element from left to right in instructions, insert it into nums.
 * The cost of each insertion is the minimum of the following:
 * 
 * 
 * The number of elements currently in nums that are strictly less than
 * instructions[i].
 * The number of elements currently in nums that are strictly greater than
 * instructions[i].
 * 
 * 
 * For example, if inserting element 3 into nums = [1,2,3,5], the cost of
 * insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is
 * greater than 3) and nums will become [1,2,3,3,5].
 * 
 * Return the total cost to insert all elements from instructions into nums.
 * Since the answer may be large, return it modulo 10^9 + 7
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: instructions = [1,5,6,2]
 * Output: 1
 * Explanation: Begin with nums = [].
 * Insert 1 with cost min(0, 0) = 0, now nums = [1].
 * Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
 * Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
 * Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
 * The total cost is 0 + 0 + 0 + 1 = 1.
 * 
 * Example 2:
 * 
 * 
 * Input: instructions = [1,2,3,6,5,4]
 * Output: 3
 * Explanation: Begin with nums = [].
 * Insert 1 with cost min(0, 0) = 0, now nums = [1].
 * Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
 * Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
 * Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
 * Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
 * Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
 * The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: instructions = [1,3,3,3,2,4,2,1,2]
 * Output: 4
 * Explanation: Begin with nums = [].
 * Insert 1 with cost min(0, 0) = 0, now nums = [1].
 * Insert 3 with cost min(1, 0) = 0, now nums = [1,3].
 * Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3].
 * Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3,3].
 * Insert 2 with cost min(1, 3) = 1, now nums = [1,2,3,3,3].
 * Insert 4 with cost min(5, 0) = 0, now nums = [1,2,3,3,3,4].
 * ​​​​​​​Insert 2 with cost min(1, 4) = 1, now nums = [1,2,2,3,3,3,4].
 * ​​​​​​​Insert 1 with cost min(0, 6) = 0, now nums = [1,1,2,2,3,3,3,4].
 * ​​​​​​​Insert 2 with cost min(2, 4) = 2, now nums = [1,1,2,2,2,3,3,3,4].
 * The total cost is 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= instructions.length <= 10^5
 * 1 <= instructions[i] <= 10^5
 * 
 */

// @lc code=start
class Solution {
public:
    int createSortedArray_TLE(vector<int>& instructions) {
        vector<int> nums(instructions.size());
        int result = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            int minN = 0, maxN = 0;
            int index = check(nums, i, instructions[i], minN, maxN);
            result += min(minN, maxN);
            insert(nums, i - 1, index, instructions[i]);
        }
        return result; 
    }
    int createSortedArray(vector<int>& instructions) {
       vector<int> nums(instructions);
       sort(nums.begin(), nums.end());
       int result = 0;
       for (int i = 0; i < instructions.size(); ++i) {
           result += checkResult(nums, i, instructions[i]);
       }
       return result; 
    }

    int checkResult(vector<int>& nums, int index, int& element) {
        int minCount = 0, maxCount = 0;
        for (int i = 0; i < index; ++i) {
            if (nums[i] < element) {
                minCount++;
            }
            else if (nums[i] > element) {
                maxCount++;
            }
        }
        return min(minCount, maxCount);
    }
private:
    int check(vector<int>& nums, int end, int& element, int& minN, int& maxN) {
        int index = end;
        for (int i = 0; i < end; ++i) {
            if (nums[i] < element) {
                ++minN;
            }
            else if (nums[i] > element) {
                if (!maxN)
                    index = i;
                ++maxN;
            }
        }
        return index;
    }

    void insert(vector<int>& nums, int end, int index, int& element) {
       for (; end >= index; --end) {
           nums[end + 1] = nums[end];
       }
       nums[index] = element;
    }
};
// @lc code=end

