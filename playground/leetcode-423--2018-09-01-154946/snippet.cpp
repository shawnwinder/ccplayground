// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [423] Reconstruct Original Digits from English
 *
 * https://leetcode.com/problems/reconstruct-original-digits-from-english/description/
 *
 * algorithms
 * Medium (44.83%)
 * Total Accepted:    16.1K
 * Total Submissions: 35.9K
 * Testcase Example:  '"owoztneoer"'
 *
 * Given a non-empty string containing an out-of-order English representation
 * of digits 0-9, output the digits in ascending order.
 *
 * Note:
 *
 * Input contains only lowercase English letters.
 * Input is guaranteed to be valid and can be transformed to its original
 * digits. That means invalid inputs such as "abc" or "zerone" are not
 * permitted.
 * Input length is less than 50,000.
 *
 *
 *
 * Example 1:
 *
 * Input: "owoztneoer"
 *
 * Output: "012"
 *
 *
 *
 * Example 2:
 *
 * Input: "fviefuro"
 *
 * Output: "45"
 *
 *
 */
class Solution {
public:
    string originalDigits(string s) {
        vector<string> t = {"one", "three", "five", "seven", "nine"};
        unordered_map<char, string> m = { 
            {'z', "zero"},
            {'w', "two"},
            {'u', "four"},
            {'x', "six"},
            {'g', "eight"}
        };
        unordered_map<char, string> m2 = {             
            {'o', "one"},
            {'r', "three"},
            {'f', "five"},
            {'s', "seven"}
        };

        unordered_map<char, int> cnt;
        unordered_map<char, int> ans;
        while (!m.empty()) {
            for (char c : s) {
                auto it = m.find(c);
                if (it != m.end()) {
                    ans[c] ++;
                    for (char x : it->second) {
                        cnt[x] ++;
                    }
                }
            }
            for (auto it=s.begin(); it !=s.end();) {
                if (cnt[*it] > 0) {
                    cnt[*it] --;
                    it = s.erase(it);
                } else it ++;
            }
            m.clear();
            swap(m, m2);
        }
        stringstream ret;
        vector<char> seq = {'z', 'o', 'w', 'r', 'u', 'f', 'x', 's', 'g'};
        for (int i=0;i<seq.size();i++) {
            for (int j=0;j<ans[seq[i]];j++) {
                ret << i;
            }
        }
        for (int i=0;i<s.size() / 4; i++) {
            ret << 9;
        }
        return ret.str();
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
