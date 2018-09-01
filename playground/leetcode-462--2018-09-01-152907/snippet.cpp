// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (51.86%)
 * Total Accepted:    27.9K
 * Total Submissions: 53.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array, find the minimum number of moves required
 * to make all array elements equal, where a move is incrementing a selected
 * element by 1 or decrementing a selected element by 1.
 *
 * You may assume the array's length is at most 10,000.
 *
 * Example:
 *
 * Input:
 * [1,2,3]
 *
 * Output:
 * 2
 *
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 *
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 *
 */
class Solution {
public:
    
    int minMoves2(vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = 0;
        int r = nums.size() -1;
        int mid = (l + r)/2;
        while (true) {
            if (l >= r) break;
            int pivot = nums[l];
            int i = l;
            int j = r;
            while (i < j) {
                while (j > i && nums[j] >= pivot) j --;
                if (j > i) nums[i] = nums[j];
                while (i < j && nums[i] < pivot) i ++;
                if (i < j) nums[j] = nums[i];
            }
            nums[i] = pivot;
            if (i < mid) l = i + 1;
            else if (i > mid) r = i;
            else break;
        }
        int cost = 0;
        for (int n: nums) {
            cost += abs(n - nums[mid]);
        }
        return cost;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
