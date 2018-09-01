// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [331] Verify Preorder Serialization of a Binary Tree
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (37.56%)
 * Total Accepted:    49.5K
 * Total Submissions: 131.8K
 * Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we
 * encounter a non-null node, we record the node's value. If it is a null node,
 * we record using a sentinel value such as #.
 *
 *
 * ⁠    _9_
 * ⁠   /   \
 * ⁠  3     2
 * ⁠ / \   / \
 * ⁠4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 *
 *
 * For example, the above binary tree can be serialized to the string
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 *
 * Given a string of comma separated values, verify whether it is a correct
 * preorder traversal serialization of a binary tree. Find an algorithm without
 * reconstructing the tree.
 *
 * Each comma separated value in the string must be either an integer or a
 * character '#' representing null pointer.
 *
 * You may assume that the input format is always valid, for example it could
 * never contain two consecutive commas such as "1,,3".
 *
 * Example 1:
 *
 *
 * Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Output: true
 *
 * Example 2:
 *
 *
 * Input: "1,#"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: "9,#,#,1"
 * Output: false
 *
 */
class Solution {
public:
  bool isValidSerialization(string preorder) {
    int sharp = 0;
    int num = 0;
    bool isnum = false;
    for (auto it = preorder.begin(); it != preorder.end(); ++it) {
      if (*it == ',') {
        isnum = false;
        continue;
      }
      if (*it != '#' && isnum) continue;
      if (num + 1 == sharp) return false;
      if (*it != '#') {
        num ++;
        isnum = true;
      } else {
        sharp ++;
        isnum = false;
      }
      if (num + 1 < sharp) return false;
    }
    if (num + 1 != sharp) return false;
    return true;
  }
};



int mymain(int argc, char *argv[]) {
    return 0;
}
