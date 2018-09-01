// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (23.74%)
 * Total Accepted:    295.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * The median is 2.0
 *
 *
 * Example 2:
 *
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            swap(nums1, nums2), swap(m, n);
        int k = (m + n + 1) >> 1;
        int l = 0, r = m;
        while (true) {
            int i = l + (r - l) / 2;
            int j = k - i;
            // if m <=n then i > 0 ==> j < n && i < m ==> j > 0
            if (i < m && nums2[j - 1] > nums1[i])
                l = i + 1;
            else if (i > 0 && nums1[i - 1] > nums2[j])
                r = i - 1;
            else {
                int maxl, minr;
                if (i == 0)
                    maxl = nums2[j - 1];
                else if (j == 0)
                    maxl = nums1[i - 1];
                else
                    maxl = max(nums1[i - 1], nums2[j - 1]);
                if ((m + n) % 2 == 1)
                    return maxl;
                if (i == m)
                    minr = nums2[j];
                else if (j == n)
                    minr = nums1[i];
                else
                    minr = min(nums1[i], nums2[j]);
                return (maxl + minr) * 0.5;
            }
        }
    }
};

int mymain(int argc, char* argv[]) { return 0; }
