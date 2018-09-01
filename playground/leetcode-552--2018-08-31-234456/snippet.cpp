// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [552] Student Attendance Record II
 *
 * https://leetcode.com/problems/student-attendance-record-ii/description/
 *
 * algorithms
 * Hard (31.61%)
 * Total Accepted:    9.1K
 * Total Submissions: 28.9K
 * Testcase Example:  '1'
 *
 * Given a positive integer n, return the number of all possible attendance
 * records with length n, which will be regarded as rewardable. The answer may
 * be very large, return it after mod 109 + 7.
 *
 * A student attendance record is a string that only contains the following
 * three characters:
 *
 *
 *
 * 'A' : Absent.
 * 'L' : Late.
 * ⁠'P' : Present.
 *
 *
 *
 *
 * A record is regarded as rewardable if it doesn't contain more than one 'A'
 * (absent) or more than two continuous 'L' (late).
 *
 * Example 1:
 *
 * Input: n = 2
 * Output: 8
 * Explanation:
 * There are 8 records with length 2 will be regarded as rewardable:
 * "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
 * Only "AA" won't be regarded as rewardable owing to more than one absent
 * times.
 *
 *
 *
 * Note:
 * The value of n won't exceed 100,000.
 *
 *
 *
 *
 */
class Solution {
public:
    int checkRecord(int n) {
        vector<long> statenoa(3, 0);
        vector<long> statea(3, 0);
        statenoa[0] = 1;
        int MOD = 1e9 + 7;
        for (int i = 1; i <=n+1; i ++) {
            long tmp = ( statenoa[0] + statenoa[1] + statenoa[2] ) % MOD;
            statenoa[2] = statenoa[1];
            statenoa[1] = statenoa[0];
            statenoa[0] = tmp;
            
            tmp = (statenoa[0] + statea[0] + statea[1] + statea[2] ) % MOD;
            statea[2] = statea[1];
            statea[1] = statea[0];
            statea[0] = tmp;
        }
        return statea[0];
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
