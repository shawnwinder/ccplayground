// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [659] Split Array into Consecutive Subsequences
 *
 * https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (37.52%)
 * Total Accepted:    11.1K
 * Total Submissions: 29.6K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * You are given an integer array sorted in ascending order (may contain
 * duplicates), you need to split them into several subsequences, where each
 * subsequences consist of at least 3 consecutive integers. Return whether you
 * can make such a split.
 *
 * Example 1:
 *
 * Input: [1,2,3,3,4,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences :
 * 1, 2, 3
 * 3, 4, 5
 *
 *
 *
 * Example 2:
 *
 * Input: [1,2,3,3,4,4,5,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences :
 * 1, 2, 3, 4, 5
 * 3, 4, 5
 *
 *
 *
 * Example 3:
 *
 * Input: [1,2,3,4,4,5]
 * Output: False
 *
 *
 *
 * Note:
 *
 * The length of the input is in range of [1, 10000]
 *
 *
 */
class Solution {
public:
    bool isPossible(vector<int>& nums) {    
        int pre = INT_MIN, p1 = 0, p2 = 0, p3 = 0;
        int cur = 0, cnt = 0, c1 = 0, c2 = 0, c3 = 0;
        for (int i = 0; i < nums.size(); pre = cur, p1 = c1, p2 = c2, p3 = c3) {
            for (cur = nums[i], cnt = 0; i < nums.size() && cur == nums[i]; cnt++, i++);
            if (cur != pre + 1) {
                if (p1 != 0 || p2 != 0) return false;
                c1 = cnt; c2 = 0; c3 = 0;
            } else {
                if (cnt < p1 + p2) return false;
                c1 = max(0, cnt - (p1 + p2 + p3));
                c2 = p1;
                c3 = p2 + min(p3, cnt - (p1 + p2));
            }
        }
        return p1 == 0 && p2 == 0;      
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
