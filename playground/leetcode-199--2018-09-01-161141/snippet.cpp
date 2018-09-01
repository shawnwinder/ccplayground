// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (44.01%)
 * Total Accepted:    122.3K
 * Total Submissions: 278K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 *
 *
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 *
 *    1            <---
 *  /   \
 * 2     3         <---
 *  \     \
 *   5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode*> q;
        vector<int> ret;
        if (!root)
            return {};
        q.push_back(root);
        while (!q.empty()) {
            vector<TreeNode*> q2;
            for (auto n : q) {
                if (n->left)
                    q2.push_back(n->left);
                if (n->right)
                    q2.push_back(n->right);
            }
            ret.push_back(q.back()->val);
            q = std::move(q2);
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
