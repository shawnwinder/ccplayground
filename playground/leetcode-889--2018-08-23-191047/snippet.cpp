// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [925] Construct Binary Tree from Preorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (52.69%)
 * Total Accepted:    2.6K
 * Total Submissions: 5K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * Return any binary tree that matches the given preorder and postorder
 * traversals.
 *
 * Values in the traversals pre and post are distinct positive integers.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * Output: [1,2,3,4,5,6,7]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= pre.length == post.length <= 30
 * pre[] and post[] are both permutations of 1, 2, ..., pre.length.
 * It is guaranteed an answer exists. If there exists multiple answers, you can
 * return any of them.
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

struct Trunk {
    Trunk* prev;
    string str;

    Trunk(Trunk* prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(ostream& os, Trunk* p) {
    if (p == nullptr)
        return;
    showTrunks(os, p->prev);
    os << p->str;
}

template <typename T> void dump(ostream& os, T* root, Trunk* prev = nullptr, bool left = true) {
    if (root == nullptr)
        return;
    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);
    dump(os, root->left, trunk, true);
    if (!prev)
        trunk->str = "---";
    else if (left) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }
    showTrunks(os, trunk);
    cout << root->val << endl;
    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";
    dump(os, root->right, trunk, false);
}

template <typename T> inline static ostream& operator<<(ostream& os, T* root) noexcept {
    dump(os, root);
    return os;
}

class Solution {
public:
    // We will **preorder** generate TreeNodes, push them to `stack` and **postorder** pop them out.
    // 1. Loop on `pre` array and construct node one by one.
    // 2. `stack` save the current path of tree.
    // 3. `node = new TreeNode(pre[i])`, if not left child, add node to the left. otherwise add it to the right.
    // 4. If we meet a same value in the pre and post, it means we complete the construction for current subtree. We pop it from `stack`.
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode*> s;
        s.push_back(new TreeNode(pre[0]));
        for (int i = 1, j = 0; i < pre.size(); ++i) {
            TreeNode* node = new TreeNode(pre[i]);
            while (s.back()->val == post[j])
                s.pop_back(), j++;
            if (s.back()->left == NULL) s.back()->left = node;
            else s.back()->right = node;
            s.push_back(node);
        }
        return s[0];
    }
};

int mymain(int argc, char *argv[]) {
    Solution s;
    vector<int> pre = {1,2,4,5,3,6,7};
    vector<int> post = {4,5,2,6,7,3,1};
    s.constructFromPrePost(pre, post);
    return 0;
}


int mymain(int argc, char* argv[]) {
    Solution s;
    vector<int> pre = { 11, 12, 14, 15, 13, 16, 17, 18, 19, 20, 21, 22, 24, 25, 23, 26, 27, 28, 29,
        30, 1, 2, 4, 5, 3, 6, 7, 8, 9, 10 };
    vector<int> post = { 28, 29, 30, 24, 25, 22, 26, 27, 23, 21, 18, 19, 20, 14, 15, 12, 16, 17, 13,
        11, 8, 9, 10, 4, 5, 2, 6, 7, 3, 1 };
    cout << s.constructFromPrePost(pre, post);
    return 0;
}
