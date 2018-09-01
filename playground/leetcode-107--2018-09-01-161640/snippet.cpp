// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (43.51%)
 * Total Accepted:    180.5K
 * Total Submissions: 414.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 *
 *
 * return its bottom-up level order traversal as:
 *
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr)
            return {};
        vector<TreeNode*> q = { root };
        int d = 0;
        while (!q.empty()) {
            vector<TreeNode*> q2;
            ret.push_back({});
            for (auto t : q) {
                ret[d].push_back(t->val);
                if (t->left)
                    q2.push_back(t->left);
                if (t->right)
                    q2.push_back(t->right);
            }
            d++;
            q = std::move(q2);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
