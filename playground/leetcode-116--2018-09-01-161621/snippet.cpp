// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (36.66%)
 * Total Accepted:    191.6K
 * Total Submissions: 522.7K
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
 * You may assume that it is a perfect binary tree (ie, all leaves are at the
 * same level, and every parent has two children).
 *
 *
 * Example:
 *
 * Given the following perfect binary tree,
 *
 *
 *     1
 *   /  \
 *  2    3
 * / \  / \
 * 4  5  6  7
 *
 *
 * After calling your function, the tree should look like:
 *
 *
 *     1 -> NULL
 *   /  \
 *  2 -> 3 -> NULL
 * / \  / \
 * 4->5->6->7 -> NULL
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
        if (!root)
            return;
        vector<TreeLinkNode*> q = { root };
        while (!q.empty()) {
            vector<TreeLinkNode*> q2;
            TreeLinkNode* l = nullptr;
            for (auto n : q) {
                if (l)
                    l->next = n;
                l = n;
                if (l->left)
                    q2.push_back(l->left);
                if (l->right)
                    q2.push_back(l->right);
            }
            q = q2;
        }
    }
};

int mymain(int argc, char* argv[]) { return 0; }
