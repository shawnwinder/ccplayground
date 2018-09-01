// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (43.05%)
 * Total Accepted:    161.9K
 * Total Submissions: 376.1K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 *
 * Example:
 *
 *
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 *
 *  1         3     3      2      1
 *   \       /     /      / \      \
 *    3     2     1      1   3      2
 *   /     /       \                 \
 *  2     1         2                 3
 *
 *
 */
class Solution {
public:
    int numTrees(int n) {
        // cantalan
        // C(2n,n)/(n+1)
        long long ans = 1;
        for (int i = n + 1; i <= 2 * n; i++) {
            ans = ans * i / (i - n);
        }
        return ans / (n + 1);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
