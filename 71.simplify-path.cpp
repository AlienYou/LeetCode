/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (33.53%)
 * Likes:    57
 * Dislikes: 43
 * Total Accepted:    247K
 * Total Submissions: 726.9K
 * Testcase Example:  '"/home/"'
 *
 * Given a string path, which is an absolute path (starting with a slash '/')
 * to a file or directory in a Unix-style file system, convert it to the
 * simplified canonical path.
 * 
 * In a Unix-style file system, a period '.' refers to the current directory, a
 * double period '..' refers to the directory up a level, and any multiple
 * consecutive slashes (i.e. '//') are treated as a single slash '/'. For this
 * problem, any other format of periods such as '...' are treated as
 * file/directory names.
 * 
 * The canonical path should have the following format:
 * 
 * 
 * The path starts with a single slash '/'.
 * Any two directories are separated by a single slash '/'.
 * The path does not end with a trailing '/'.
 * The path only contains the directories on the path from the root directory
 * to the target file or directory (i.e., no period '.' or double period
 * '..')
 * 
 * 
 * Return the simplified canonical path.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: path = "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: path = "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: path = "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: path = "/a/./b/../../c/"
 * Output: "/c"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= path.length <= 3000
 * path consists of English letters, digits, period '.', slash '/' or '_'.
 * path is a valid absolute Unix path.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string simplifyPath1(string path) {
        string result;
        for (int i = 0; i < path.length(); ++i) {
            int count = 0;
            if (path[i] == '/') {
                ++i;
                while (i < path.length() && path[i] == '/')
                    ++i;
                if (i < path.length()) {
                    int left = i - 1;
                    while (i < path.length() && path[i] != '/') {    
                        if (path[i] == '.')
                            count++;
                        ++i;
                    }
                    if (count == 0 || i - 1 - left >= 3) {
                        while (left < i) {
                            result.push_back(path[left++]);
                        }
                    }
                    else if (count == 2) {
                        while (result.length() > 0 && result[result.length() - 1] != '/') {
                            result.pop_back();
                        }
                        if (result.length() >= 1)
                            result.pop_back();
                    }
                    --i;
                }
            }
        }
        if (result.length() == 0 && path.length() > 0)
            result.push_back('/');
        return result;
    }
    
    string simplifyPath(string path) {
        string result = "", token;
        vector<string> tokens;
        stringstream ss(path);
        while (getline(ss, token, '/')) {
            if (token == "." || token == "")
                continue;
            if (token == "..") {
                if (tokens.size() > 0)
                    tokens.pop_back();
            }
            else 
                tokens.push_back(token);
        }
        
        if (tokens.size() == 0) return "/";
        
        for (auto el : tokens) {
            result += "/" + el;
        }
        return result;
    }
};
// @lc code=end

