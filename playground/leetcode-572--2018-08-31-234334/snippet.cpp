// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (40.38%)
 * Total Accepted:    61.7K
 * Total Submissions: 152.8K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 *
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 *
 *
 * Example 1:
 *
 * Given tree s:
 *
 *     3
 *    / \
 *   4   5
 *  / \
 * 1   2
 *
 * Given tree t:
 *
 *   4
 *  / \
 * 1   2
 *
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 *
 *
 * Example 2:
 *
 * Given tree s:
 *
 *     3
 *    / \
 *   4   5
 *  / \
 * 1   2
 *    /
 *   0
 *
 * Given tree t:
 *
 *   4
 *  / \
 * 1   2
 *
 * Return false.
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
    bool isEqual(TreeNode* s, TreeNode* t) {
        if (s != nullptr && t != nullptr) 
            return s->val == t->val && isEqual(s->left, t->left) && isEqual(s->right, t->right);
        if (s == nullptr && t == nullptr) return true;
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == nullptr) return true;
        if (s != nullptr && t != nullptr) 
            return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        if (s == nullptr) return false;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
