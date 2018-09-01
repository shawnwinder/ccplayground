// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [655] Print Binary Tree
 *
 * https://leetcode.com/problems/print-binary-tree/description/
 *
 * algorithms
 * Medium (48.90%)
 * Total Accepted:    11.7K
 * Total Submissions: 24K
 * Testcase Example:  '[1,2]'
 *
 * Print a binary tree in an m*n 2D string array following these rules:
 *
 *
 * The row number m should be equal to the height of the given binary tree.
 * The column number n should always be an odd number.
 * The root node's value (in string format) should be put in the exactly middle
 * of the first row it can be put. The column and the row where the root node
 * belongs will separate the rest space into two parts (left-bottom part and
 * right-bottom part). You should print the left subtree in the left-bottom
 * part and print the right subtree in the right-bottom part. The left-bottom
 * part and the right-bottom part should have the same size. Even if one
 * subtree is none while the other is not, you don't need to print anything for
 * the none subtree but still need to leave the space as large as that for the
 * other subtree. However, if two subtrees are none, then you don't need to
 * leave space for both of them.
 * Each unused space should contain an empty string "".
 * Print the subtrees following the same rules.
 *
 *
 * Example 1:
 *
 * Input:
 *     1
 *    /
 *   2
 * Output:
 * [["", "1", ""],
 * ["2", "", ""]]
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 *     1
 *    / \
 *   2   3
 *    \
 *     4
 * Output:
 * [["", "", "", "1", "", "", ""],
 * ["", "2", "", "", "", "3", ""],
 * ["", "", "4", "", "", "", ""]]
 *
 *
 *
 * Example 3:
 *
 * Input:
 *      1
 *     / \
 *    2   5
 *   /
 *  3
 * /
 * 4
 * Output:
 *
 * [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 * ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 * ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 * ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
 *
 *
 *
 * Note:
 * The height of binary tree is in the range of [1, 10].
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
    int dep(TreeNode* root) {
        if (root==nullptr) return 0;
        return 1 + max(dep(root->left), dep(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = dep(root);
        if (h == 0) return {};
        vector<vector<string>> ret(h, vector<string>((1 << h) - 1, ""));
        using pp=pair<int, TreeNode*>; 
        deque<pp> q = {{0, root}};
        deque<pp> q2;
        int d = 0;
        while (!q.empty()) {
            while (!q.empty()) {
                auto x = q.front().first;
                auto y = q.front().second;
                ret[d][(1 << (h - d - 1)) - 1 + x * (1 << (h - d))] = to_string(y->val);
                q.pop_front();
                if (y->left) q2.push_back({x<<1, y->left});
                if (y->right) q2.push_back({(x<<1) + 1, y->right});
            }
            swap(q, q2);
            d ++;
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
