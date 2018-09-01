// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (47.22%)
 * Total Accepted:    268.2K
 * Total Submissions: 568.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */
class Solution {
public:
    vector<int> elem;
    vector<int> time;
    vector<vector<int>> ans;

    void work(vector<int>& buf, int pos) {
        if(pos == elem.size()) {
            ans.push_back(buf);
            return;
        }
        work(buf, pos+1);
        for (int i=0; i< time[pos]; i++) {
            buf.push_back(elem[pos]);
            work(buf, pos+1);
        }
        
        for (int i=0; i< time[pos]; i++) {
            buf.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(auto it=nums.begin(); it!=nums.end(); it ++) {
            
            int n = 1;
            while(it+1 != nums.end() && *(it+1) ==*it) {
                it ++;
                n ++;
            }
            elem.push_back(*it);
            time.push_back(n);
        }
        vector<int> buf;
        work(buf, 0);
        
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
