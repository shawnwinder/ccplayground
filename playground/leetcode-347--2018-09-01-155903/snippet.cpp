// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (50.70%)
 * Total Accepted:    127K
 * Total Submissions: 250.5K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Note:
 *
 *
 * You may assume k is always valid, 1 <= k <= number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 *
 *
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        int mf = 0;
        for (int x : nums)
            mf = max(mf, ++f[x]);
        vector<int> c(mf + 1, 0);
        for (auto& x : f)
            c[x.second]++;
        int l = nums.size();
        for (int i = mf; k > 0; i--)
        {
            k -= c[i];
            l = i;
        }
        vector<int> ans;
        for (auto& x : f)
            if (x.second > l || (x.second == l && ++k > 0))
                ans.push_back(x.first);
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
