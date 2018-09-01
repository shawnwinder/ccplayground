// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [475] Heaters
 *
 * https://leetcode.com/problems/heaters/description/
 *
 * algorithms
 * Easy (29.90%)
 * Total Accepted:    33.7K
 * Total Submissions: 112.7K
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * Winter is coming! Your first job during the contest is to design a standard
 * heater with fixed warm radius to warm all the houses.
 *
 * Now, you are given positions of houses and heaters on a horizontal line,
 * find out minimum radius of heaters so that all houses could be covered by
 * those heaters.
 *
 * So, your input will be the positions of houses and heaters seperately, and
 * your expected output will be the minimum radius standard of heaters.
 *
 * Note:
 *
 * Numbers of houses and heaters you are given are non-negative and will not
 * exceed 25000.
 * Positions of houses and heaters you are given are non-negative and will not
 * exceed 10^9.
 * As long as a house is in the heaters' warm radius range, it can be warmed.
 * All the heaters follow your radius standard and the warm radius will the
 * same.
 *
 *
 *
 * Example 1:
 *
 * Input: [1,2,3],[2]
 * Output: 1
 * Explanation: The only heater was placed in the position 2, and if we use the
 * radius 1 standard, then all the houses can be warmed.
 *
 *
 *
 * Example 2:
 *
 * Input: [1,2,3,4],[1,4]
 * Output: 1
 * Explanation: The two heater was placed in the position 1 and 4. We need to
 * use radius 1 standard, then all the houses can be warmed.
 *
 *
 */
class Solution {
public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    int r = 0;
    sort(heaters.begin(), heaters.end());
    sort(houses.begin(), houses.end());
    auto it = heaters.begin();
    for (int x: houses) {
      it = lower_bound(it, heaters.end(), x);
      int t = it != heaters.end() ? *it-x : INT_MAX;
      if (it != heaters.begin()) t = min(t, x-it[-1]);
      r = max(r, t);
    }
    return r;
  }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
