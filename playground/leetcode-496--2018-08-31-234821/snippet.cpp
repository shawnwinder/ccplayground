// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [496] Next Greater Element I
 *
 * https://leetcode.com/problems/next-greater-element-i/description/
 *
 * algorithms
 * Easy (56.89%)
 * Total Accepted:    66.2K
 * Total Submissions: 116.4K
 * Testcase Example:  '[4,1,2]\n[1,3,4,2]'
 *
 *
 * You are given two arrays (without duplicates) nums1 and nums2 where nums1's
 * elements are subset of nums2. Find all the next greater numbers for nums1's
 * elements in the corresponding places of nums2.
 *
 *
 *
 * The Next Greater Number of a number x in nums1 is the first greater number
 * to its right in nums2. If it does not exist, output -1 for this number.
 *
 *
 * Example 1:
 *
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * Output: [-1,3,-1]
 * Explanation:
 *    For number 4 in the first array, you cannot find the next greater number
 * for it in the second array, so output -1.
 *    For number 1 in the first array, the next greater number for it in the
 * second array is 3.
 *    For number 2 in the first array, there is no next greater number for it
 * in the second array, so output -1.
 *
 *
 *
 * Example 2:
 *
 * Input: nums1 = [2,4], nums2 = [1,2,3,4].
 * Output: [3,-1]
 * Explanation:
 *    For number 2 in the first array, the next greater number for it in the
 * second array is 3.
 *    For number 4 in the first array, there is no next greater number for it
 * in the second array, so output -1.
 *
 *
 *
 *
 * Note:
 *
 * All elements in nums1 and nums2 are unique.
 * The length of both nums1 and nums2 would not exceed 1000.
 *
 *
 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        if(nums.empty()) return {};
        unordered_map<int, int> m;
        vector<int> s;
        for (int i=0;i<nums.size()-1; i++) {
            if(nums[i] < nums[i+1]) {
                m[nums[i]] = nums[i+1];
                while (!s.empty()) {
                    if (s.back() < nums[i+1]) {
                        m[s.back()] = nums[i+1];
                        s.pop_back();
                    } else break;
                }
            } else s.push_back(nums[i]);
        }
        m[nums.back()] = -1;
        while (!s.empty()) {
            m[s.back()] = -1;
            s.pop_back();
        }
        vector<int> ans;
        for(int i=0;i<findNums.size();i++) {
            ans.push_back(m[findNums[i]]);
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
