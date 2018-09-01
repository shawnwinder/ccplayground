// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.32%)
 * Total Accepted:    43.5K
 * Total Submissions: 148.3K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 *
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 *
 *
 *
 * Note:
 *
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means .
 *
 *
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int s = INT_MAX;
        int t = INT_MIN;
        int n = nums.size();
        bool flag = false;
        for (int i=1;i<n;i++) {
            if (nums[i] < nums[i-1]) {
                flag = true;
            }
            if (flag) s = min(s, nums[i]);
        }
        flag = false;
        for (int i = n-2;i>=0;i--) {
            if (nums[i] > nums[i+1]) {
                flag = true;
            }
            if (flag) t = max(t, nums[i]);
        }
        
        int i=0;
        int j=0;
        for (i=0;i<n;i++) {
            if (nums[i] > s) break;
        }
        if (i == n) return 0;
        for (j=n-1;j>=0;j--) {
            if (nums[j] < t) break;
        }
        return j-i+1;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
