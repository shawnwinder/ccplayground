// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [473] Matchsticks to Square
 *
 * https://leetcode.com/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (35.38%)
 * Total Accepted:    19K
 * Total Submissions: 53.6K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * Remember the story of Little Match Girl? By now, you know exactly what
 * matchsticks the little match girl has, please find out a way you can make
 * one square by using up all those matchsticks. You should not break any
 * stick, but you can link them up, and each matchstick must be used exactly
 * one time.
 *
 * ⁠Your input will be several matchsticks the girl has, represented with their
 * stick length. Your output will either be true or false, to represent whether
 * you could make one square using all the matchsticks the little match girl
 * has.
 *
 * Example 1:
 *
 * Input: [1,1,2,2,2]
 * Output: true
 *
 * Explanation: You can form a square with length 2, one side of the square
 * came two sticks with length 1.
 *
 *
 *
 * Example 2:
 *
 * Input: [3,3,3,3,4]
 * Output: false
 *
 * Explanation: You cannot find a way to form a square with all the
 * matchsticks.
 *
 *
 *
 * Note:
 *
 * The length sum of the given matchsticks is in the range of 0 to 10^9.
 * The length of the given matchstick array will not exceed 15.
 *
 *
 */
class Solution {
public:
    int cnt;
    bool makesquare(vector<int>& nums) {
        if (!nums.size()) return false;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % 4) return false;
        
        int target = sum / 4;
        cnt = 0;
        
        for (int i = 0; i < 4; i++) {
            vector<int> path;
            if (!dfs(nums, target, 0, path)) return false;
            for (int j = path.size()-1; j >= 0; j--) {
                nums.erase(nums.begin()+path[j]);
            }
        }
        return true;
    }
    
    bool dfs(vector<int>& nums, int target, int start, vector<int>& path) {
        if (target == 0) {
            return true;
        }
        
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > target) continue;
            path.push_back(i);
            if (dfs(nums, target-nums[i], i+1, path)) return true;
            path.pop_back();
        }
        return false;
    }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
