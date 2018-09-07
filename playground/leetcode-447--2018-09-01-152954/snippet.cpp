// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (47.51%)
 * Total Accepted:    42K
 * Total Submissions: 88.4K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 *
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 *
 * Example:
 *
 * Input:
 * [[0,0],[1,0],[2,0]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 *
 *
 */
class Solution {
public:
    int dis(pair<int, int> a, pair<int, int> b) {
        return pow(b.second - a.second, 2) + pow(b.first - a.first, 2);
    }
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ret = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> m;
            for (int j = 0; j < points.size(); j++) {
                m[dis(points[i], points[j])]++;
            }
            for (auto& e : m) {
                int n = e.second;
                ret += n * (n - 1);
            }
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
