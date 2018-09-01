// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [365] Water and Jug Problem
 *
 * https://leetcode.com/problems/water-and-jug-problem/description/
 *
 * algorithms
 * Medium (28.34%)
 * Total Accepted:    22.2K
 * Total Submissions: 78.4K
 * Testcase Example:  '3\n5\n4'
 *
 * You are given two jugs with capacities x and y litres. There is an infinite
 * amount of water supply available. You need to determine whether it is
 * possible to measure exactly z litres using these two jugs.
 *
 * If z liters of water is measurable, you must have z liters of water
 * contained within one or both buckets by the end.
 *
 * Operations allowed:
 *
 *
 * Fill any of the jugs completely with water.
 * Empty any of the jugs.
 * Pour water from one jug into another till the other jug is completely full
 * or the first jug itself is empty.
 *
 *
 * Example 1: (From the famous "Die Hard" example)
 *
 *
 * Input: x = 3, y = 5, z = 4
 * Output: True
 *
 *
 * Example 2:
 *
 *
 * Input: x = 2, y = 6, z = 5
 * Output: False
 *
 *
 */
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || x + y >= z && z % gcd(x, y) == 0;
    }
private:
    int gcd(int x, int y) {
        if (!x) return INT_MAX;
        return y == 0? x : gcd(y, x%y);
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
