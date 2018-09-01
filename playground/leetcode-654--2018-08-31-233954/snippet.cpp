// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (70.86%)
 * Total Accepted:    45K
 * Total Submissions: 63.6K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 *
 * Given an integer array with no duplicates. A maximum tree building on this
 * array is defined as follow:
 *
 * The root is the maximum number in the array.
 * The left subtree is the maximum tree constructed from left part subarray
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray
 * divided by the maximum number.
 *
 *
 *
 *
 * Construct the maximum tree by the given array and output the root node of
 * this tree.
 *
 *
 * Example 1:
 *
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 *
 *      6
 *    /   \
 *   3     5
 *    \    /
 *     2  0
 *       \
 *        1
 *
 *
 *
 * Note:
 *
 * The size of the given array will be in the range [1,1000].
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
    TreeNode* partition(vector<int>& nums, int s, int t) {
        if (s >= t) return nullptr;
        int m = INT_MIN;
        int k = -1;
        for (int i=s;i<t;i++) {
            if (m < nums[i]) {
                m = nums[i];
                k = i;
            }
        }
        TreeNode* ret = new TreeNode(m);
        ret->left = partition(nums, s, k);
        ret->right = partition(nums, k+1, t);
        return ret;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return partition(nums, 0, nums.size());
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
