// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (32.76%)
 * Total Accepted:    33.3K
 * Total Submissions: 101.7K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You have a number of envelopes with widths and heights given as a pair of
 * integers (w, h). One envelope can fit into another if and only if both the
 * width and height of one envelope is greater than the width and height of the
 * other envelope.
 *
 * What is the maximum number of envelopes can you Russian doll? (put one
 * inside other)
 *
 * Note:
 * Rotation is not allowed.
 *
 * Example:
 *
 *
 *
 * Input: [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 *
 *
 *
 */
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& es) {
        sort(es.begin(), es.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });
        vector<int> dp;
        for (auto e : es) {
            auto iter = lower_bound(dp.begin(), dp.end(), e.second);
            if (iter == dp.end())
                dp.push_back(e.second);
            else if (e.second < *iter)
                *iter = e.second;
        }
        return dp.size();
    }
};

int mymain(int argc, char* argv[]) { return 0; }
