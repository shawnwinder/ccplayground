// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (44.93%)
 * Total Accepted:    38.6K
 * Total Submissions: 85.9K
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string representing an attendance record for a student. The
 * record only contains the following three characters:
 *
 *
 *
 * 'A' : Absent.
 * 'L' : Late.
 * 'P' : Present.
 *
 *
 *
 *
 * A student could be rewarded if his attendance record doesn't contain more
 * than one 'A' (absent) or more than two continuous 'L' (late).
 *
 * You need to return whether the student could be rewarded according to his
 * attendance record.
 *
 * Example 1:
 *
 * Input: "PPALLP"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "PPALLL"
 * Output: False
 *
 *
 *
 *
 *
 */
class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A')
                a++;
            if (s[i] == 'L')
                l++;
            else
                l = 0;
            if (a >= 2 || l > 2)
                return false;
        }
        return true;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
