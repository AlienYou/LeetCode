/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (49.23%)
 * Likes:    4037
 * Dislikes: 187
 * Total Accepted:    419.7K
 * Total Submissions: 841.2K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,2]
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
// Encodes a tree to a single string.
    string serialize1(TreeNode* root) {
        if (root == nullptr)
            return "";
        string result;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur != nullptr) {
                    result += to_string(cur->val) + ',';
                    que.push(cur->left);
                    que.push(cur->right);
                } else 
                    result += "null,";
            }
        }
        cout << result << endl;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize1(string data) {
        if (data.length() == 0)
            return nullptr;
        vector<string> vec;
        for (int i = 0, pre = i; i <= data.length(); ++i) {
            if (data[i] == ',') {
                vec.push_back(data.substr(pre, i - pre));
                pre = i + 1;
            }
        }
        int index = 0;
        TreeNode* root = new TreeNode(atoi(vec[index++].c_str()));
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            string left = vec[index++];
            string right = vec[index++];
            if (left != "null") {
                cur->left = new TreeNode(atoi(left.c_str()));
                que.push(cur->left);    
            }
            if (right != "null") {
                cur->right = new TreeNode(atoi(right.c_str()));
                que.push(cur->right);
            }
        }
        return root;
    }
    
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "null,";
        string res;
        res += to_string(root->val) + ',';
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }
    
    TreeNode* deserialize(string data) {
        vector<string> vec;
        for (int i = 0, pre = i; i <= data.length(); ++i) {
            if (data[i] == ',') {
                vec.push_back(data.substr(pre, i - pre));
                pre = i + 1;
            }
        }
        int i = 0;
        return core(vec, i);
    }
    
    TreeNode* core(vector<string>& strs, int& i) {
        if (strs[i] == "null")
            return nullptr;
        TreeNode* root = new TreeNode(atoi(strs[i].c_str()));
        i++;
        root->left = core(strs, i);
        i++;
        root->right = core(strs, i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

