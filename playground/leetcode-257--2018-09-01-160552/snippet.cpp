// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (42.77%)
 * Total Accepted:    177.8K
 * Total Submissions: 415.8K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 *
 * Input:
 *
 *   1
 *  / \
 * 2   3
 *  \
 *   5
 *
 * Output: ["1->2->5", "1->3"]
 *
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    string join(vector<string>& d) {
        string sep = "";
        stringstream ss;
        for (auto& s : d) {
            ss << sep << s;
            sep = "->";
        }
        return ss.str();
    }
    void solve(vector<string>& ans, TreeNode* root, vector<string>& partial) {
        if (!root)
            return;
        partial.push_back(to_string(root->val));
        if (!root->left && !root->right)
            ans.push_back(join(partial));
        if (root->left)
            solve(ans, root->left, partial);
        if (root->right)
            solve(ans, root->right, partial);
        partial.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<string> p;
        solve(ans, root, p);
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
