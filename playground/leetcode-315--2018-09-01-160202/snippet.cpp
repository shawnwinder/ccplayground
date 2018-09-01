// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (35.48%)
 * Total Accepted:    54.6K
 * Total Submissions: 153.8K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 *
 * Example:
 *
 *
 * Input: [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 *
 *
 */
class Solution {
public:
  vector<int> countSmaller(vector<int>& nums) {
    n = nums.size();
    t.resize(n*2);

    vector<int> sn = nums;
    sort(sn.begin(), sn.end());
    sn.erase(unique(sn.begin(), sn.end()), sn.end());
    int i=0;
    for (auto& x : sn) {
      m[x] = i++;
    }

    vector<int> res(nums.size());
    for (auto i = nums.rbegin(); i != nums.rend(); ++i) {
      int p = nums.size() - 1 - (i - nums.rbegin());
      res[p] = query(0, m[*i]);
      update(m[*i], 1);
    }
    return res;
  }

  void update(int i, int val) {
    for (t[i += n] += val; i>1; i >>=1) {
      t[i>>1] = t[i] + t[i^1];
    }
  }

  int query(int i, int j) {
    int res = 0;
    for (i += n, j +=n; i<j; i>>=1, j>>=1 ) {
      if (i&1) res += t[i++];
      if (j&1) res += t[--j];
    }
    return res;
  }

private:
  vector<int> t;
  int n;
  unordered_map<int, int> m;
};


int mymain(int argc, char *argv[]) {
    return 0;
}
