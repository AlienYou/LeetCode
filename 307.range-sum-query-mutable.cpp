/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (36.38%)
 * Likes:    1689
 * Dislikes: 101
 * Total Accepted:    128.8K
 * Total Submissions: 351.5K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an array nums and two types of queries where you should update the
 * value of an index in the array, and retrieve the sum of a range in the
 * array.
 * 
 * Implement the NumArray class:
 * 
 * 
 * NumArray(int[] nums) Initializes the object with the integer array nums.
 * void update(int index, int val) Updates the value of nums[index] to be
 * val.
 * int sumRange(int left, int right) Returns the sum of the subarray nums[left,
 * right] (i.e., nums[left] + nums[left + 1], ..., nums[right]).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * Output
 * [null, 9, null, 8]
 * 
 * Explanation
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // return 9 = sum([1,3,5])
 * numArray.update(1, 2);   // nums = [1,2,5]
 * numArray.sumRange(0, 2); // return 8 = sum([1,2,5])
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -100 <= nums[i] <= 100
 * 0 <= index < nums.length
 * -100 <= val <= 100
 * 0 <= left <= right < nums.length
 * At most 3 * 10^4 calls will be made to update and sumRange.
 * 
 * 
 */

// @lc code=start
struct SegmentTreeNode {
    int start;
    int end;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    int sum;
    SegmentTreeNode(int start, int end) {
        this->start = start;
        this->end = end;
        this->left = nullptr;
        this->right = nullptr;
        this->sum = 0;
    }
};

class NumArray {
public:   
    /*NumArray(vector<int>& nums) {
        if (nums.size() > 0) {
            n = nums.size();
            tree.resize(2 * n);
            buildTree(nums);
        }
    }*/
    
    NumArray(vector<int>& nums) {
        this->root = buildTree(nums, 0, nums.size() - 1);
    }
    
    void update1(int index, int val) {
        index += n;
        tree[index] = val;
        while (index > 0) {
            int left = index;
            int right = index;
            if (index % 2 == 0) {
                right = index + 1;
            } else {
                left = index - 1;
            }
            tree[index >> 1] = tree[left] + tree[right];
            index >>= 1;
        }
    }
    
    void update(int index, int val) {
       update(root, index, val);
    }
    
    void update(SegmentTreeNode* root, int pos, int val) {
        if (root->start == root->end)
            root->sum = val;
        else {
            int mid = root->start + (root->end - root->start) / 2;
            if (pos <= mid) {
                update(root->left, pos, val);
            } else {
                update(root->right, pos, val);
            }
            root->sum = root->left->sum + root->right->sum;
        }
    }
    
    int sumRange(int left, int right) {
        return sumRange(root, left, right);
    }
    
    int sumRange(SegmentTreeNode* root, int start, int end) {
        if (root->start == start && root->end == end) {
            return root->sum;
        } else {
            int mid = root->start + (root->end - root->start) / 2;
            if (end <= mid) {
                return sumRange(root->left, start, end);
            } else if (start > mid) {
                return sumRange(root->right, start, end);
            } else {
                return sumRange(root->right, mid + 1, end) + sumRange(root->left, start, mid);
            }
        }
    }
    
    int sumRange1(int left, int right) {
        left += n;
        right += n;
        int sum = 0;
        while (left <= right) {
            if (left % 2) {
                sum += tree[left];
                left++;
            }
            if (right % 2 == 0) {
                sum += tree[right];
                right--;
            }
            left >>= 1;
            right >>= 1;
        }
        return sum;
    }
private:
    SegmentTreeNode* root = nullptr;
    SegmentTreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        } else {
            SegmentTreeNode* ret = new SegmentTreeNode(start, end);
            if (start == end) {
                ret->sum = nums[start];
            } else {
                int mid = start + (end - start) / 2;
                ret->left = buildTree(nums, start, mid);
                ret->right= buildTree(nums, mid + 1, end);
                ret->sum = ret->left->sum + ret->right->sum;
            }
            return ret;
        }
    }
    
private:
    void buildTree(vector<int>& nums) {
        for (int i = n, j = 0; i < 2 * n; ++i, ++j) {
            tree[i] = nums[j];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }    
    
private:
    vector<int> tree;
    int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

