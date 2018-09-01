// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <stack>

using namespace std;

/*
 * [173] Binary Search Tree Iterator
 *
 * https://leetcode.com/problems/binary-search-tree-iterator/description/
 *
 * algorithms
 * Medium (44.45%)
 * Total Accepted:    147.7K
 * Total Submissions: 332.4K
 * Testcase Example:  '[]'
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h)
 * memory, where h is the height of the tree.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
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

class BSTIterator {
private:
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) { find_left(root); }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty())
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            find_left(top->right);

        return top->val;
    }

    /** put all the left child() of root */
    void find_left(TreeNode* root) {
        TreeNode* p = root;
        while (p != NULL) {
            st.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int mymain(int argc, char* argv[]) { return 0; }
