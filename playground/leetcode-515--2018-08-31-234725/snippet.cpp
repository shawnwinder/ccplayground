// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (56.12%)
 * Total Accepted:    46.8K
 * Total Submissions: 83.4K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 *
 * Example:
 *
 * Input:
 *
 *          1
 *         / \
 *        3   2
 *       / \   \
 *      5   3   9
 *
 * Output: [1, 3, 9]
 *
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
    vector<int> largestValues(TreeNode* root) {
        vector<TreeNode*> q, q2;
        vector<int> ret;
        if (root == NULL) return {};
        q.push_back(root);
        while(!q.empty()) {
            int ans = INT_MIN;
            for (auto n : q) {
                if (n == NULL) continue;
                if (n->val > ans) ans = n->val;
                q2.push_back(n->left);
                q2.push_back(n->right);
            }
            if (!q2.empty()) ret.push_back(ans);
            q.clear();
            swap(q, q2);
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
