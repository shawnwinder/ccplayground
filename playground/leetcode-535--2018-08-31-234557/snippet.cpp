// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * [535] Encode and Decode TinyURL
 *
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (74.11%)
 * Total Accepted:    48.7K
 * Total Submissions: 65.7K
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
class Solution {
    int autoIncrement = 1;
    unordered_map<string, int> dictionary;
    string encodeTable = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string getStringFromAutoIncrement(int aHashValue) {
        string basic = "https://";
        while (aHashValue != 0) {
            int reminder = aHashValue % 62;
            basic += encodeTable[reminder];
            aHashValue /= 62;
        }
        return basic;
    }

    int getAutoIncrementFromString(string aShortUrl) {
        string basic(aShortUrl);
        basic.erase(0, 8); // remove "https://"
        int hashValue = 0;
        float index = 0;
        for (int i = 0; i < basic.size(); i++) {
            size_t loc = encodeTable.find(basic[i]);
            hashValue += loc * pow(62, index);
            index++;
        }
        return hashValue;
    }

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto iter = dictionary.find(longUrl);
        int hashValue = 0;
        if (iter == dictionary.end())
            hashValue = dictionary[longUrl] = autoIncrement++;
        else
            hashValue = iter->second;
        string encoded = getStringFromAutoIncrement(hashValue); // change hashValue to string;
        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int hashValue = getAutoIncrementFromString(shortUrl);
        for (auto& iter : dictionary) {
            if (iter.second == hashValue) {
                return iter.first;
            }
        }
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int mymain(int argc, char* argv[]) { return 0; }
