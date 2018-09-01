// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (31.77%)
 * Total Accepted:    47.1K
 * Total Submissions: 148.3K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 *
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 *
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]]
 * Explanation: The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [1,1],[1,1]
 * Explanation: The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 *
 * Example 3:
 *
 *
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [1,3],[2,3]
 * Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 *
 *
 */
class Solution {
public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    typedef pair<int, int> pii;
    vector<pii> r;
    if (nums1.empty() || nums2.empty())
      return r;
    auto cmp = [&](const pii& x, const pii& y) {
      return nums1[x.first]+nums2[x.second] > nums1[y.first]+nums2[y.second];
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    pq.emplace(0, 0);
    while (k-- && pq.size()) {
      pii x = pq.top();
      pq.pop();
      r.emplace_back(nums1[x.first], nums2[x.second]);
      if (x.first+1 < nums1.size())
        pq.emplace(x.first+1, x.second);
      if (!x.first && x.second+1 < nums2.size())
        pq.emplace(x.first, x.second+1);
    }
    return r;
  }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
