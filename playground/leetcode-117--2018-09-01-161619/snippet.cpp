// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (33.62%)
 * Total Accepted:    144.9K
 * Total Submissions: 431K
 * Testcase Example:  '{}'
 *
 * Given a binary tree
 *
 *
 * struct TreeLinkNode {
 *  TreeLinkNode *left;
 *  TreeLinkNode *right;
 *  TreeLinkNode *next;
 * }
 *
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 *
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra
 * space for this problem.
 *
 *
 * Example:
 *
 * Given the following binary tree,
 *
 *
 *      1
 *    /  \
 *   2    3
 *  / \    \
 * 4   5    7
 *
 *
 * After calling your function, the tree should look like:
 *
 *
 *      1 -> NULL
 *    /  \
 *   2 -> 3 -> NULL
 *  / \    \
 * 4-> 5 -> 7 -> NULL
 *
 *
 */

#ifdef CC_PLAYGROUND
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
        , next(NULL) {}
};
#endif

class Solution {
public:
    void connect(TreeLinkNode* root) {
        TreeLinkNode* s = root;
        TreeLinkNode *b, *t;
        while (1) {
            while (s && s->left == NULL && s->right == NULL)
                s = s->next;
            if (s == NULL)
                break;
            b = t = s->left ? s->left : s->right;
            while (s) {
                if (t == s->left && s->right) {
                    t->next = s->right;
                    t = t->next;
                } else if (t == s->left && !s->right || t == s->right)
                    s = s->next;
                else {
                    while (s && s->left == NULL && s->right == NULL)
                        s = s->next;
                    if (s == NULL)
                        break;
                    t->next = s->left ? s->left : s->right;
                    t = t->next;
                }
            }
            s = b;
        }
    }
};

int mymain(int argc, char* argv[]) { return 0; }
