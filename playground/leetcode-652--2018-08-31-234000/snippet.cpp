// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (39.23%)
 * Total Accepted:    19.9K
 * Total Submissions: 50.8K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * Given a binary tree, return all duplicate subtrees. For each kind of
 * duplicate subtrees, you only need to return the root node of any one of
 * them.
 *
 * Two trees are duplicate if they have the same structure with same node
 * values.
 *
 * Example 1:
 *
 *
 *        1
 *       / \
 *      2   3
 *     /   / \
 *    4   2   4
 *       /
 *      4
 *
 *
 * The following are two duplicate subtrees:
 *
 *
 *      2
 *     /
 *    4
 *
 *
 * and
 *
 *
 *    4
 *
 * Therefore, you need to return above trees' root in the form of a list.
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map;
        vector<TreeNode*> dups;
        serialize(root, map);
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second.size() > 1) {
                dups.push_back(it->second[0]);
            }
        }

        return dups;
    }

private:
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& map) {
        if (!node) return "";
        string s = "(" + serialize(node->left, map) + to_string(node->val) + serialize(node->right, map) + ")";
        map[s].push_back(node);
        return s;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
