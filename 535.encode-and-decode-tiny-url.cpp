/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 *
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (80.67%)
 * Likes:    802
 * Dislikes: 1677
 * Total Accepted:    124.4K
 * Total Submissions: 153.2K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * Note: This is a companion problem to the System Design problem: Design
 * TinyURL.
 * 
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such
 * as http://tinyurl.com/4e9iAk.
 * 
 * Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need
 * to ensure that a URL can be encoded to a tiny URL and the tiny URL can be
 * decoded to the original URL.
 * 
 */

// @lc code=start
class Solution {
public:
public:
    const string alpha = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> urlMap;
    
    string getRandom() {
        string res;
        for (int i = 0; i < 6; ++i) {
            res.push_back(alpha[rand() % 62]);
        }
        return res;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = getRandom();
        while (urlMap.count(key)) {
            key = getRandom();
        }
        key = "http://tinyurl.com/" + key;
        urlMap[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urlMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

