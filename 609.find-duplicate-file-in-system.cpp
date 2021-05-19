/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 *
 * https://leetcode.com/problems/find-duplicate-file-in-system/description/
 *
 * algorithms
 * Medium (60.78%)
 * Likes:    663
 * Dislikes: 809
 * Total Accepted:    81.1K
 * Total Submissions: 128.9K
 * Testcase Example:  '["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]'
 *
 * Given a list paths of directory info, including the directory path, and all
 * the files with contents in this directory, return all the duplicate files in
 * the file system in terms of their paths. You may return the answer in any
 * order.
 * 
 * A group of duplicate files consists of at least two files that have the same
 * content.
 * 
 * A single directory info string in the input list has the following
 * format:
 * 
 * 
 * "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ...
 * fn.txt(fn_content)"
 * 
 * 
 * It means there are n files (f1.txt, f2.txt ... fn.txt) with content
 * (f1_content, f2_content ... fn_content) respectively in the directory
 * "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the
 * directory is just the root directory.
 * 
 * The output is a list of groups of duplicate file paths. For each group, it
 * contains all the file paths of the files that have the same content. A file
 * path is a string that has the following format:
 * 
 * 
 * "directory_path/file_name.txt"
 * 
 * 
 * 
 * Example 1:
 * Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c
 * 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
 * Output:
 * [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
 * Example 2:
 * Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c
 * 3.txt(abcd)","root/c/d 4.txt(efgh)"]
 * Output:
 * [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= paths.length <= 2 * 10^4
 * 1 <= paths[i].length <= 3000
 * 1 <= sum(paths[i].length) <= 5 * 10^5
 * paths[i] consist of English letters, digits, '/', '.', '(', ')', and '
 * '.
 * You may assume no files or directories share the same name in the same
 * directory.
 * You may assume each given directory info represents a unique directory. A
 * single blank space separates the directory path and file info.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Imagine you are given a real file system, how will you search files? DFS or
 * BFS?
 * If the file content is very large (GB level), how will you modify your
 * solution?
 * If you can only read the file by 1kb each time, how will you modify your
 * solution?
 * What is the time complexity of your modified solution? What is the most
 * time-consuming part and memory-consuming part of it? How to optimize?
 * How to make sure the duplicated files you find are not false positive?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> strMap;
        
        for (string& curStr : paths) {
            handleBlank(curStr, strMap);
        }
        for (auto& ele : strMap) {
            if (ele.second.size() >= 2)
                res.push_back(ele.second);
        }
        return res;
    }
    
    void handleBlank(string& curStr, unordered_map<string, vector<string>>& strMap) {
        int cur = 0;
        vector<string> splitVec;
        for (int i = 0; i <= curStr.length(); ++i) {
            if (i == curStr.length() || curStr[i] == ' ') {
                splitVec.emplace_back(curStr.substr(cur, i - cur));
                cur = i + 1;
            }
        }
        for (int i = 1; i < splitVec.size(); ++i) {
            for (int j = 0; j < splitVec[i].size(); ++j) {
                if (splitVec[i][j] == '(') {
                    string s = splitVec[i].substr(j + 1, splitVec[i].length() - 1);
                    strMap[s].emplace_back(splitVec[0] + '/' + splitVec[i].substr(0, j));
                }
            }
        }
    }
};
// @lc code=end

