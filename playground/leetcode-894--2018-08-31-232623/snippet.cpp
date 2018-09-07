// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [930] All Possible Full Binary Trees
 *
 * https://leetcode.com/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (64.15%)
 * Total Accepted:    2.9K
 * Total Submissions: 4.5K
 * Testcase Example:  '7'
 *
 * A full binary tree is a binary tree where each node has exactly 0 or 2
 * children.
 *
 * Return a list of all possible full binary trees with N nodes.  Each element
 * of the answer is the root node of one possible tree.
 *
 * Each node of each tree in the answer must have node.val = 0.
 *
 * You may return the final list of trees in any order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 7
 * Output:
 * [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 * Explanation:
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 20
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
    vector<TreeNode*> allFBT(int n) {
        vector<TreeNode*> ans;
        if (n == 1) {
            TreeNode* a = new TreeNode(0);
            ans.push_back(a);
            return ans;
        }
        if (n < 1 || n % 2 == 0)
            return ans;
        for (int i = 1; i < n; i = i + 2) {
            vector<TreeNode*> lans = allFBT(i);
            vector<TreeNode*> rans = allFBT(n - i - 1);
            for (int j = 0; j < lans.size(); j++) {
                for (int k = 0; k < rans.size(); k++) {
                    TreeNode* r = new TreeNode(0);
                    r->left = lans[j];
                    r->right = rans[k];
                    ans.push_back(r);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode*> allPossibleFBT(int N) { return allFBT(N); }
};

int mymain(int argc, char* argv[]) { return 0; }
