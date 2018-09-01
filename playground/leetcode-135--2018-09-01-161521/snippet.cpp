// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (25.96%)
 * Total Accepted:    83.5K
 * Total Submissions: 321.7K
 * Testcase Example:  '[1,0,2]'
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 *
 * You are giving candies to these children subjected to the following
 * requirements:
 *
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 *
 *
 * What is the minimum candies you must give?
 *
 * Example 1:
 *
 *
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 *
 *
 * Example 2:
 *
 *
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * ⁠            The third child gets 1 candy because it satisfies the above two
 * conditions.
 *
 *
 */
class Solution {
public:

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 0) return 0;
        vector<int> l = vector<int>(n, 1);
        vector<int> r = l;
        int ans = 0;
        for(int i=1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) {
                l[i] = l[i-1] + 1;
            }
        }
        for(int i=n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                r[i] = r[i+1] + 1;
            }
        }
        
        for(int i=0;i<n;i++) {
            ans += max(l[i], r[i]);
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
