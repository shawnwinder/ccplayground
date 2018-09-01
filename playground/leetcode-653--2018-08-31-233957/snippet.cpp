// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (50.54%)
 * Total Accepted:    53.7K
 * Total Submissions: 106.3K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 *
 * Example 1:
 *
 * Input:
 *    5
 *   / \
 *  3   6
 * / \   \
 * 2   4   7
 *
 * Target = 9
 *
 * Output: True
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 *    5
 *   / \
 *  3   6
 * / \   \
 * 2   4   7
 *
 * Target = 28
 *
 * Output: False
 *
 *
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
    void collect(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;
        collect(root->left, v);
        v.push_back(root->val);
        collect(root->right, v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        collect(root, v);
        if (v.size() < 2) return false;
        int slow = 0;
        int fast = v.size() - 1;
        while (slow < fast) {
            if (v[slow] + v[fast] > k) fast --;
            else if (v[slow] + v[fast] < k) slow ++;
            else return true;
        }
        return false;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
