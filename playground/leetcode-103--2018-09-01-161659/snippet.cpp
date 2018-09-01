// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (38.14%)
 * Total Accepted:    156.3K
 * Total Submissions: 409.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<TreeNode*> q = { root };
        vector<vector<int>> ans;
        bool lr = true;
        while (!q.empty()) {
            vector<TreeNode*> q2;
            vector<int> tmp;
            reverse(q.begin(), q.end());
            for (auto e : q) {
                if (lr) {
                    if (e->left)
                        q2.push_back(e->left);
                    if (e->right)
                        q2.push_back(e->right);
                } else {
                    if (e->right)
                        q2.push_back(e->right);
                    if (e->left)
                        q2.push_back(e->left);
                }
            }
            transform(q.begin(), q.end(), back_inserter(tmp), [](TreeNode* t) { return t->val; });
            ans.push_back(tmp);
            q = q2;
            lr = !lr;
        }
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
