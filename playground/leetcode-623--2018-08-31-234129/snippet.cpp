// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [623] Add One Row to Tree
 *
 * https://leetcode.com/problems/add-one-row-to-tree/description/
 *
 * algorithms
 * Medium (46.14%)
 * Total Accepted:    18.7K
 * Total Submissions: 40.5K
 * Testcase Example:  '[4,2,6,3,1,5]\n1\n2'
 *
 * Given the root of a binary tree, then value v and depth d, you need to add a
 * row of nodes with value v at the given depth d. The root node is at depth
 * 1.
 *
 * The adding rule is: given a positive integer depth d, for each NOT null tree
 * nodes N in depth d-1, create two tree nodes with value v as N's left subtree
 * root and right subtree root. And N's original left subtree should be the
 * left subtree of the new left subtree root, its original right subtree should
 * be the right subtree of the new right subtree root. If depth d is 1 that
 * means there is no depth d-1 at all, then create a tree node with value v as
 * the new root of the whole original tree, and the original tree is the new
 * root's left subtree.
 *
 * Example 1:
 *
 * Input:
 * A binary tree as following:
 *       4
 *     /   \
 *    2     6
 *   / \   /
 *  3   1 5
 *
 * v = 1
 *
 * d = 2
 *
 * Output:
 *       4
 *      / \
 *     1   1
 *    /     \
 *   2       6
 *  / \     /
 * 3   1   5
 *
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 * A binary tree as following:
 *      4
 *     /
 *    2
 *   / \
 *  3   1
 *
 * v = 1
 *
 * d = 3
 *
 * Output:
 *      4
 *     /
 *    2
 *   / \
 *  1   1
 * /     \
 * 3       1
 *
 *
 *
 * Note:
 *
 * The given d is in range [1, maximum depth of the given tree + 1].
 * The given binary tree has at least one tree node.
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        deque<TreeNode*> q;
        deque<TreeNode*> q2;
        auto proot = new TreeNode(0);
        proot->left = root;
        q.push_back(proot);
        int dep = 0;
        while (!q.empty()) {
            dep ++;
            if (dep == d) {
                for (auto t : q) {
                                            auto l = new TreeNode(v);
                    l->left = t->left;
                    t->left = l;
                    
                    auto r = new TreeNode(v);
                    r->right = t->right;
                    t->right = r;
                    
                }
                break;
            }
            for (auto t: q) {
                if (t->left) q2.push_back(t->left);
                if (t->right) q2.push_back(t->right);
            }
            swap(q, q2);
            q2.clear();
        }
        root = proot->left;
        delete proot;
        return root;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
