// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (33.11%)
 * Total Accepted:    111.1K
 * Total Submissions: 335.5K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 *
 *  1         3     3      2      1
 *   \       /     /      / \      \
 *    3     2     1      1   3      2
 *   /     /       \                 \
 *  2     1         2                 3
 *
 *
 */

#ifdef CC_PLAYGROUND
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL) {}
};
#endif

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp(n, vector<vector<TreeNode*>>(n));
        vector<TreeNode*> nil = { nullptr };
        for (int i = n; i >= 0; i--)
            for (int j = i; j < n; j++)
                for (int k = i; k <= j; k++)
                    for (auto lt : k > i ? dp[i][k - 1] : nil)
                        for (auto rt : k < j ? dp[k + 1][j] : nil) {
                            auto r = new TreeNode(k + 1);
                            r->left = lt;
                            r->right = rt;
                            dp[i][j].push_back(r);
                        }
        return n ? dp[0][n - 1] : vector<TreeNode*>();
    }
};

int mymain(int argc, char* argv[]) { return 0; }
