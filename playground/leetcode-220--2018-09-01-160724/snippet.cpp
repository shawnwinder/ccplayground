// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (18.90%)
 * Total Accepted:    74.6K
 * Total Submissions: 394.6K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the absolute difference between nums[i] and
 * nums[j] is at most t and the absolute difference between i and j is at most
 * k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 *
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 *
 *
 *
 *
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2) return false;
        if (t < 0 || k < 1) return false;
        unordered_map<long, long> m;
        int l = 0;
        long lt = t;
        for (int i=0;i<nums.size();i++) {
 
            long b = ((long)nums[i] + INT_MIN) / (lt + 1);
            if (m.find(b) != m.end() || 
                (m.find(b-1) != m.end() && nums[i] - m[b-1] <= lt) || 
                (m.find(b+1) != m.end() && m[b+1] -nums[i] <= lt)) return true;
                        m[b] = nums[i];

           if (i-l >= k) { 
                m.erase(((long)nums[l] + INT_MIN) / (lt + 1));
                l ++;
            }
        }
        return false;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
