// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (34.60%)
 * Total Accepted:    134.2K
 * Total Submissions: 387.7K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * Example:
 *
 *
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 *
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *partition(ListNode *p, int x) {
    ListNode *lh = nullptr, *lt = nullptr, *gh = nullptr, *gt = nullptr;
    for (; p; p = p->next)
      if (p->val < x) {
        if (! lh)
          lh = lt = p;
        else
          lt->next = p, lt = p;
      } else {
        if (! gh)
          gh = gt = p;
        else
          gt->next = p, gt = p;
      }
    if (lt)
      lt->next = gh;
    if (gt)
      gt->next = nullptr;
    return lh ? lh : gh;
  }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
