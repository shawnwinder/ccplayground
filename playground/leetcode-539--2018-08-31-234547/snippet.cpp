// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * [539] Minimum Time Difference
 *
 * https://leetcode.com/problems/minimum-time-difference/description/
 *
 * algorithms
 * Medium (46.49%)
 * Total Accepted:    19.7K
 * Total Submissions: 42.4K
 * Testcase Example:  '["23:59","00:00"]'
 *
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the
 * minimum minutes difference between any two time points in the list.
 *
 * Example 1:
 *
 * Input: ["23:59","00:00"]
 * Output: 1
 *
 *
 *
 * Note:
 *
 * The number of time points in the given list is at least 2 and won't exceed
 * 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 *
 *
 */
class Solution {
    int timeDiff(string t1, string t2) {
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 2));
        return (h2 - h1) * 60 + (m2 - m1);
    }

public:
    int findMinDifference(vector<string>& times) {
        int n = times.size();
        sort(times.begin(), times.end());
        int mindiff = INT_MAX;
        for (int i = 0; i < n; i++) {
            int diff = abs(timeDiff(times[(i - 1 + n) % n], times[i]));
            diff = min(diff, 1440 - diff);
            mindiff = min(mindiff, diff);
        }
        return mindiff;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
