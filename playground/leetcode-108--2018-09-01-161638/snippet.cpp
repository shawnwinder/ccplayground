// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (46.22%)
 * Total Accepted:    196K
 * Total Submissions: 424.1K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 * Example:
 *
 *
 * Given the sorted array: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 *
 *       0
 *      / \
 *    -3   9
 *    /   /
 *  -10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (j == -1)
            j = nums.size();
        if (i >= j)
            return nullptr;
        int m = (i + j) / 2;
        auto ret = new TreeNode(nums[m]);
        int lj = j;
        j = m;
        ret->left = sortedArrayToBST(nums);
        j = lj;
        int li = i;
        i = m + 1;
        ret->right = sortedArrayToBST(nums);
        i = li;
        return ret;
    }

private:
    int i = 0;
    int j = -1;
};

int mymain(int argc, char* argv[]) { return 0; }
