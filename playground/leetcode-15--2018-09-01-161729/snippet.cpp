// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (22.00%)
 * Total Accepted:    371.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res;
        if (num.size() <= 2)
            return res;
        sort(num.begin(), num.end());
        int twoSum;
        for (int i = 0; i < num.size() - 2;) {
            int l = i + 1, r = num.size() - 1;
            twoSum = 0 - num[i];
            while (l < r) {
                if (num[l] + num[r] < twoSum)
                    l++;
                else if (num[l] + num[r] == twoSum) {
                    res.push_back(vector<int>{ num[i], num[l], num[r] });
                    do {
                        l++;
                    } while (l < r && num[l - 1] == num[l]);
                    do {
                        r--;
                    } while (l < r && num[r + 1] == num[r]);
                } else
                    r--;
            }
            do {
                i++;
            } while (i < num.size() - 1 && num[i - 1] == num[i]);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
