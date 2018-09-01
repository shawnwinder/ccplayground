// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [477] Total Hamming Distance
 *
 * https://leetcode.com/problems/total-hamming-distance/description/
 *
 * algorithms
 * Medium (47.79%)
 * Total Accepted:    37.6K
 * Total Submissions: 78.6K
 * Testcase Example:  '[4,14,2]'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 *
 * Now your job is to find the total Hamming distance between all pairs of the
 * given numbers.
 *
 *
 * Example:
 *
 * Input: 4, 14, 2
 *
 * Output: 6
 *
 * Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is
 * 0010 (just
 * showing the four bits relevant in this case). So the answer will be:
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2
 * + 2 + 2 = 6.
 *
 *
 *
 * Note:
 *
 * Elements of the given array are in the range of 0  to 10^9
 * Length of the array will not exceed 10^4.
 *
 *
 */
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        long ret = 0;
        for (auto i = 0u; i < 32; ++i) {
            long cnt = 0;
            for (auto elem : nums) {
                cnt += (elem & (1 << i)) > 0;
            }
            ret += cnt * (nums.size() - cnt);
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}


int mymain(int argc, char *argv[]) {
    return 0;
}
