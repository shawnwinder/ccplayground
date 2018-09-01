// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.97%)
 * Total Accepted:    281.2K
 * Total Submissions: 703.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 *
 *
 * Example 2:
 *
 *
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 *
 *
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for(i=digits.size()-1; i>=0; i--) {
            if (digits[i] < 9) break;
        }
        if(i == -1) {
            for(int j=1; j<digits.size(); j++) digits[j] = 0;
            digits[0] = 1;
            digits.push_back(0);
        } else {
            for(int j=i+1;j<digits.size(); j++) digits[j] = 0;
            digits[i] ++;
        }
        return digits;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
