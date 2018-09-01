// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (24.13%)
 * Total Accepted:    103.2K
 * Total Submissions: 427.6K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 *
 * Example 1:
 *
 *
 * Input: [10,2]
 * Output: "210"
 *
 * Example 2:
 *
 *
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 *
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
                stringstream sa ;
                stringstream sb ;
                sa << a << b;
                sb << b << a;
                return sa.str() > sb.str();
            });
        stringstream ss;
        if (!nums.empty() && nums[0] == 0) ss << "0";
        else for (auto n : nums) ss << n;
        return ss.str();
    }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
