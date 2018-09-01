// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (39.17%)
 * Total Accepted:    157.7K
 * Total Submissions: 402.7K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Example:
 *
 *
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 */
class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        int r = 0;
        unordered_set<int> s;
        for (auto i : num)
            s.insert(i);
        for (auto i : num) {
            int j = i, k = i + 1;
            while (s.count(j - 1))
                s.erase(j--);
            while (s.count(k))
                s.erase(k++);
            r = max(r, k - j);
        }
        return r;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
