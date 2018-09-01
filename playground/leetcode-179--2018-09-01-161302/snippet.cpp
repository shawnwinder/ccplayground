// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

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
    string largestNumber(vector<int>& num) {
        vector<string> arr;
        for (auto i : num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](string& s1, string& s2) { return s1 + s2 > s2 + s1; });
        string res;
        for (auto s : arr)
            res += s;
        while (res[0] == '0' && res.length() > 1)
            res.erase(0, 1);
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
