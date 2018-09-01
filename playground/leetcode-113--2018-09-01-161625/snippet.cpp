// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (37.17%)
 * Total Accepted:    181.9K
 * Total Submissions: 489.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given the below binary tree and sum = 22,
 *
 *
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 *
 *
 * Return:
 *
 *
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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
    vector<vector<int>> ans;
    vector<int> state;
    int sum;
    void dfs(TreeNode* root, int psum) {
        if (!root) return;
        state.push_back(root->val), psum += root->val;
        if (!root->left && !root->right && sum == psum) ans.push_back(state);
        else dfs(root->left, psum), dfs(root->right, psum);
        state.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        this->sum = sum;
        dfs(root, 0);
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
