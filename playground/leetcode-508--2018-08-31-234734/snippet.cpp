// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (52.74%)
 * Total Accepted:    36.5K
 * Total Submissions: 69.3K
 * Testcase Example:  '[5,2,-3]'
 *
 *
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 *
 *
 * Examples 1
 * Input:
 *
 *  5
 * /  \
 * 2   -3
 *
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 *
 *
 * Examples 2
 * Input:
 *
 *  5
 * /  \
 * 2   -5
 *
 * return [2], since 2 happens twice, however -5 only occur once.
 *
 *
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
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
    int sum(TreeNode* root, unordered_map<int, int>& m) {
        if (root == NULL) return 0;
        root->val += sum(root->left, m);
        root->val += sum(root->right, m);
        m[root->val] ++;
        return root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root == NULL) return {};
        unordered_map<int, int> m;
        sum(root, m);
        int ans = 0;
        vector<int> ret;
        for (auto& p : m) {
            int k = p.first;
            int v = p.second;
            if (v > ans) {
                ans = v;
                ret = {k};
            } else if (v == ans) {
                ret.push_back(k);
            }
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
