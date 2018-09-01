// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (45.65%)
 * Total Accepted:    74.9K
 * Total Submissions: 164.1K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 *
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3,null,3,null,1]
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \
 * ⁠    3   1
 *
 * Output: 7
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *
 * Example 2:
 *
 *
 * Input: [3,4,5,1,3,null,1]
 *
 * 3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \
 * ⁠1   3   1
 *
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, bool can_rob) {
        if (root == nullptr) return 0;
        int ret = solve(root->left, true) + solve(root->right, true);
        if (can_rob) ret = max(ret, root->val + solve(root->left, false) + solve(root->right, false));
        return ret;
    }
    int rob(TreeNode* root) {
        return solve(root, true);
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
