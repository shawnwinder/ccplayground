// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [493] Reverse Pairs
 *
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (20.99%)
 * Total Accepted:    14.7K
 * Total Submissions: 70.1K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * Given an array nums, we call (i, j) an important reverse pair if i < j and
 * nums[i] > 2*nums[j].
 *
 * You need to return the number of important reverse pairs in the given
 * array.
 *
 * Example1:
 *
 * Input: [1,3,2,3,1]
 * Output: 2
 *
 *
 * Example2:
 *
 * Input: [2,4,3,5,1]
 * Output: 3
 *
 *
 * Note:
 *
 * The length of the given array will not exceed 50,000.
 * All the numbers in the input array are in the range of 32-bit integer.
 *
 *
 */
class Solution {
public:
  int reversePairs(vector<int> nums) {
    n = nums.size();
    t.resize(n*2);

    vector<long> sn(nums.begin(), nums.end());
    sort(sn.begin(), sn.end());
    sn.erase(unique(sn.begin(), sn.end()), sn.end());
    int i=0;
    for (auto& x : sn) {
      m[x] = i++;
    }

    for (int l = 0, r = 0; r < sn.size(); r ++) {
      while (sn[r] > 2 * sn[l] && l < sn.size()) l++;
      if (l == sn.size()) as[sn[r]] = i;
      else as[sn[r]] = m[sn[l]];
    }
    _(as);
    _(m);

    int res = 0;
    for (auto i = nums.rbegin(); i != nums.rend(); ++i) {
      res += query(0, as[*i]);
      update(m[*i], 1);
    }
    return res;
  }

  void update(int i, int val) {
    for (t[i += n] += val; i > 1; i >>= 1) t[i >> 1] = t[i] + t[i^1];
  }

  int query(int i, int j) {
    int res = 0;
    for (i += n, j += n; i<j; i >>= 1, j >>=1) {
      if (i & 1) res += t[i++];
      if (j & 1) res += t[--j];
    }
    return res;
  }
private:
  vector<int> t;
  int n;
  unordered_map<int, int> m;
  unordered_map<int, int> as;
};


int mymain(int argc, char *argv[]) {
    return 0;
}
