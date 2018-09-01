// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (36.21%)
 * Total Accepted:    160.9K
 * Total Submissions: 444.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 *
 * Return the following binary tree:
 *
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        return solve(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

private:
    using it = vector<int>::iterator;
    TreeNode* solve(it l, it r, it ll, it rr) {
        if (l == r)
            return nullptr;
        auto root = new TreeNode(*l);
        auto mid = find(ll, rr, *l);
        root->left = solve(l + 1, l + 1 + (mid - ll), ll, mid);
        root->right = solve(l + 1 + (mid - ll), r, mid + 1, rr);
        return root;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
