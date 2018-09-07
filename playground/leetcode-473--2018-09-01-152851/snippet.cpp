// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
 * [473] Matchsticks to Square
 *
 * https://leetcode.com/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (35.38%)
 * Total Accepted:    19K
 * Total Submissions: 53.6K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * Remember the story of Little Match Girl? By now, you know exactly what
 * matchsticks the little match girl has, please find out a way you can make
 * one square by using up all those matchsticks. You should not break any
 * stick, but you can link them up, and each matchstick must be used exactly
 * one time.
 *
 * Your input will be several matchsticks the girl has, represented with their
 * stick length. Your output will either be true or false, to represent whether
 * you could make one square using all the matchsticks the little match girl
 * has.
 *
 * Example 1:
 *
 * Input: [1,1,2,2,2]
 * Output: true
 *
 * Explanation: You can form a square with length 2, one side of the square
 * came two sticks with length 1.
 *
 *
 *
 * Example 2:
 *
 * Input: [3,3,3,3,4]
 * Output: false
 *
 * Explanation: You cannot find a way to form a square with all the
 * matchsticks.
 *
 *
 *
 * Note:
 *
 * The length sum of the given matchsticks is in the range of 0 to 10^9.
 * The length of the given matchstick array will not exceed 15.
 *
 *
 */
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        long sum = accumulate(nums.begin(), nums.end(), 0l);
        if (sum % 4)
            return false;
        long sideLen = sum / 4;
        // need to solve the problem of partitioning nums into four equal subsets each having
        // sum equal to sideLen
        vector<int> usedMasks;
        // validHalfSubsets[i] == true iff the subset represented by bitmask i
        // has sum == 2*sideLen, AND the subset represented by i can be further partitioned into
        // two equal subsets. See below for how it is used.
        vector<bool> validHalfSubsets(1 << n, false);
        int all = (1 << n) - 1;
        // go through all possible subsets each represented by a bitmask
        for (int mask = 0; mask <= all; mask++) {
            long subsetSum = 0;
            // calculate the sum of this subset
            for (int i = 0; i < 32; i++) {
                if ((mask >> i) & 1)
                    subsetSum += nums[i];
            }
            // if this subset has what we want
            if (subsetSum == sideLen) {
                for (int usedMask : usedMasks) {
                    // if this mask and usedMask are mutually exclusive
                    if ((usedMask & mask) == 0) {
                        // then they form a valid half subset whose sum is 2 * sideLen,
                        // that can be further partitioned into two equal subsets (usedMask and
                        // mask)
                        int validHalf = usedMask | mask;
                        validHalfSubsets[validHalf] = true;
                        // if in the past we concluded that the other half is also a valid
                        // half subset, DONE!
                        if (validHalfSubsets[all ^ validHalf])
                            return true;
                    }
                }
                usedMasks.push_back(mask);
            }
        }
        return false;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
