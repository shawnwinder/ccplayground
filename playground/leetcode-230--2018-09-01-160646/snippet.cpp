// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (47.03%)
 * Total Accepted:    162K
 * Total Submissions: 344.5K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 <= k <= BST's total elements.
 *
 * Example 1:
 *
 *
 * Input: root = [3,1,4,null,2], k = 1
 *   3
 *  / \
 * 1   4
 *  \
 *   2
 * Output: 1
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 *       5
 *      / \
 *     3   6
 *    / \
 *   2   4
 *  /
 * 1
 * Output: 3
 *
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
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
    int kthSmallest(TreeNode* root, int k) {
        auto p = root;
        while (p) {
            auto l = p->left;
            if (l) {
                while (l->right && l->right != p)
                    l = l->right;
                if (l->right == p) {
                    l->right = nullptr;
                } else {
                    l->right = p;
                    p = p->left;
                    continue;
                }
            }
            if (--k == 0)
            {
                // stupid OJ cannot destruct the tree
                root->left = nullptr;
                root->right = nullptr;
                return p->val;
            }
            p = p->right;
        }
        return -1;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
