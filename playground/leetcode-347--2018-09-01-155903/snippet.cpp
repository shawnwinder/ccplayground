// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

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
        unordered_map<int, int> c;
        for (int n: nums) {
            c[n] ++;
        }
        using pp=pair<int, int>;
        vector<pp> ans;
        transform(c.begin(), c.end(), back_inserter(ans), [](pp e) {
            return pp(e.second, e.first);
        });
        
        int s = 0;
        int t = ans.size();
        while (s < t) {
            int pivot = ans[s].first;
            int i = s;
            int j = s;
            int n = t-1;
            while (j<=n) {
                if (ans[j].first > pivot) {
                    swap(ans[j], ans[i]);
                    i++;
                    j++;
                } else if (ans[j].first < pivot) {
                    swap(ans[n], ans[j]);
                    n--;
                } else j++;
            }
            if (i<k && (k-1)<=n) {
                vector<int> ret;
                for(int x=0;x<k;x++) {
                    ret.push_back(ans[x].second);
                }
                return ret;
            } else if (k <= i) {
                t = i;
            } else {
                s = n + 1;
            }
        }
        return {};
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
