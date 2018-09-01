// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [606] Construct String from Binary Tree
 *
 * https://leetcode.com/problems/construct-string-from-binary-tree/description/
 *
 * algorithms
 * Easy (50.25%)
 * Total Accepted:    42.8K
 * Total Submissions: 85.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * You need to construct a string consists of parenthesis and integers from a
 * binary tree with the preorder traversing way.
 *
 * The null node needs to be represented by empty parenthesis pair "()". And
 * you need to omit all the empty parenthesis pairs that don't affect the
 * one-to-one mapping relationship between the string and the original binary
 * tree.
 *
 * Example 1:
 *
 * Input: Binary tree: [1,2,3,4]
 *       1
 *     /   \
 *    2     3
 *   /
 *  4
 *
 * Output: "1(2(4))(3)"
 * Explanation: Originallay it needs to be "1(2(4)())(3()())", but you need to
 * omit all the unnecessary empty parenthesis pairs. And it will be
 * "1(2(4))(3)".
 *
 *
 *
 * Example 2:
 *
 * Input: Binary tree: [1,2,3,null,4]
 *       1
 *     /   \
 *    2     3
 *     \
 *      4
 *
 * Output: "1(2()(4))(3)"
 * Explanation: Almost the same as the first example, except we can't omit the
 * first parenthesis pair to break the one-to-one mapping relationship between
 * the input and the output.
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
    string tree2str(TreeNode* t) {
        if (t == NULL) return "";
        stringstream ret;
        ret << t->val;
        if (t->left != NULL) ret << "(" << tree2str(t->left) << ")";
        if (t->left == NULL && t->right != NULL) ret << "()";
        if (t->right != NULL) ret << "(" << tree2str(t->right) << ")";
        return ret.str();
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
