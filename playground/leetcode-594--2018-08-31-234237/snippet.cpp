// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (41.51%)
 * Total Accepted:    25.5K
 * Total Submissions: 61.5K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmonious array is an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 *
 * Now, given an integer array, you need to find the length of its longest
 * harmonious subsequence among all its possible subsequences.
 *
 * Example 1:
 *
 * Input: [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 *
 *
 *
 * Note:
 * The length of the input array will not exceed 20,000.
 *
 *
 *
 */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int s = 0;
        unordered_map<int, int> c;
        for (int x : nums)
            c[x]++;
        for (auto& x : c)
            if (c.count(x.first + 1))
                s = max(s, x.second + c[x.first + 1]);
        return s;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
