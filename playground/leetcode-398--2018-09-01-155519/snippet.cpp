// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [398] Random Pick Index
 *
 * https://leetcode.com/problems/random-pick-index/description/
 *
 * algorithms
 * Medium (45.82%)
 * Total Accepted:    40.3K
 * Total Submissions: 88K
 * Testcase Example:  '["Solution","pick"]\n[[[1,2,3,3,3]],[3]]'
 *
 * Given an array of integers with possible duplicates, randomly output the
 * index of a given target number. You can assume that the given target number
 * must exist in the array.
 *
 * Note:
 * The array size can be very large. Solution that uses too much extra space
 * will not pass the judge.
 *
 * Example:
 *
 *
 * int[] nums = new int[] {1,2,3,3,3};
 * Solution solution = new Solution(nums);
 *
 * // pick(3) should return either index 2, 3, or 4 randomly. Each index should
 * have equal probability of returning.
 * solution.pick(3);
 *
 * // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
 * solution.pick(1);
 *
 *
 */
class Solution {
public:
    Solution(vector<int> nums) : d(nums) {

    }
    
    int pick(int target) {
        int cnt = 0;
        int ans = -1;
        for (int i=0;i<d.size();i++) {
            if (d[i] == target) {
                cnt ++;
                uniform_int_distribution<int> ud(1, cnt);
                if (ud(gen) == cnt) ans = i;
            }
        }
        return ans;
    }
private:
    default_random_engine gen;
    vector<int> d;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int mymain(int argc, char *argv[]) {
    return 0;
}
