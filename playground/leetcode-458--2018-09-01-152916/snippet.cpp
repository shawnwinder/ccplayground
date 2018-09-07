#include <cmath>
// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [458] Poor Pigs
 *
 * https://leetcode.com/problems/poor-pigs/description/
 *
 * algorithms
 * Easy (43.37%)
 * Total Accepted:    12K
 * Total Submissions: 27.6K
 * Testcase Example:  '1000\n15\n60'
 *
 * There are 1000 buckets, one and only one of them contains poison, the rest
 * are filled with water. They all look the same. If a pig drinks that poison
 * it will die within 15 minutes. What is the minimum amount of pigs you need
 * to figure out which bucket contains the poison within one hour.
 *
 * Answer this question, and write an algorithm for the follow-up general
 * case.
 *
 * Follow-up:
 *
 * If there are n buckets and a pig drinking poison will die within m minutes,
 * how many pigs (x) you need to figure out the "poison" bucket within p
 * minutes? There is exact one bucket with poison.
 *
 */
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int r = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(r));
    }
};

int mymain(int argc, char* argv[]) { return 0; }
