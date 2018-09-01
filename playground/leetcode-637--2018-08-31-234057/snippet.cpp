// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (56.47%)
 * Total Accepted:    55.3K
 * Total Submissions: 98K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 *
 * Example 1:
 *
 * Input:
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 *
 *
 *
 * Note:
 *
 * The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*> q;
        vector<TreeNode*> q2;
        vector<double> ans;
        q.push_back(root);
        while (!q.empty()) {
            double sum = 0;
            int cnt = 0;
            for (int i = 0; i<q.size(); i++) {
                if (q[i] != NULL) {
                    sum += q[i]->val;
                    cnt ++;
                    q2.push_back(q[i]->left);
                    q2.push_back(q[i]->right);
                }
            }
            if (cnt == 0) break;
            ans.push_back(sum/cnt);
            q.clear();
            swap(q, q2);
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
