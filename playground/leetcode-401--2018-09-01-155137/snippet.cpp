// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (44.80%)
 * Total Accepted:    52.7K
 * Total Submissions: 117.6K
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 *
 * For example, the above binary watch reads "3:25".
 *
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 *
 * Example:
 * Input: n = 1
 * Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 *
 *
 * Note:
 *
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 *
 *
 */
class Solution {
public:
    void solve(vector<string>& ans, int b, int num, int h, int m) {
        if (num == 0) {
            ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
            return;
        }
        if (10 - b < num)
            return;
        for (int i = b; i < 10; i++) {
            if (i < 4 && (1 << i) + h <= 11) {
                solve(ans, i + 1, num - 1, (1 << i) + h, m);
            } else if (i >= 4 && (1 << (i - 4)) + m <= 59) {
                solve(ans, i + 1, num - 1, h, (1 << (i - 4)) + m);
            }
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        if (num <= 0 && num >= 9)
            return ret;
        solve(ret, 0, num, 0, 0);
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
