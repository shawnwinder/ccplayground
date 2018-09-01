// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

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
    int lowbit(int x) {
        return x & (-x);
    }
    void modify(vector<int>& a, int x,int add) {
        while(x<a.size()) {
            a[x]+=add;
            x+=lowbit(x);
        }
    }
    int get_sum(vector<int>& a, int x) {
        int ret=0;
        while(x!=0) {
            ret+=a[x];
            x-=lowbit(x);
        }
        return ret;
    }

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto a = envelopes;
        sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
          return x.first != y.first ? x.first < y.first : x.second > y.second;
        });
        vector<int> b;
        for (auto& x: a) {
          auto t = lower_bound(b.begin(), b.end(), x.second);
          if (b.end() == t)
            b.push_back(x.second);
          else
            *t = x.second;
        }
        return b.size();

    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
