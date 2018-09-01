// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (30.07%)
 * Total Accepted:    39.9K
 * Total Submissions: 132.7K
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * Suppose you have a long flowerbed in which some of the plots are planted and
 * some are not. However, flowers cannot be planted in adjacent plots - they
 * would compete for water and both would die.
 *
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means
 * empty and 1 means not empty), and a number n, return if n new flowers can be
 * planted in it without violating the no-adjacent-flowers rule.
 *
 * Example 1:
 *
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 *
 *
 *
 * Note:
 *
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 *
 *
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.push_back(0);
        int l = 1;
        for (int x : flowerbed) {
            if (x == 0) l ++;
            else l = 0;
            if (l == 3) {
                n --;
                if (n <= 0) return true;
                l = 1;
            }
        }
        return n <= 0;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
