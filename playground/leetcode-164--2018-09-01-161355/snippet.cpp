// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (30.74%)
 * Total Accepted:    59.8K
 * Total Submissions: 194.5K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 *
 * Return 0 if the array contains less than 2 elements.
 *
 * Example 1:
 *
 *
 * Input: [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either
 * (3,6) or (6,9) has the maximum difference 3.
 *
 * Example 2:
 *
 *
 * Input: [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return 0.
 *
 * Note:
 *
 *
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * Try to solve it in linear time/space.
 *
 *
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        if (nums.size() < 2) return 0;
        int B = 11;
        int R = 1<<B;
        int M = R-1;
        int N = 32;

        vector<int> count = vector<int>(R+1);
        vector<int> aux = vector<int>(nums.size());
        for (int i = 0; i < N; i+=B) {
            fill(count.begin(), count.end(), 0);
            for (int v : nums)
                count[((v >> i) & M) + 1]++;
    
            for (int r = 1; r < R; r++)
                count[r + 1] += count[r];
    
            for (int v : nums)
                aux[count[(v >> i) & M]++] = v;
                
    
            for (int j = 0; j < nums.size(); j++)
                nums[j] = aux[j];
        }
    
        int res = INT_MIN;
        for (int i = 1; i < nums.size(); i++) 
            res = max(nums[i] - nums[i -1], res);
    
        return res; 
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
