// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (49.25%)
 * Total Accepted:    152.7K
 * Total Submissions: 310.1K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 *
 *
 * Note:
 *
 *
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 *
 *
 *
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(int n:nums1) s1.insert(n);
        for(int n:nums2) {
            if (s1.count(n)) s2.insert(n);
        }
        vector<int> ret(s2.begin(), s2.end());
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
