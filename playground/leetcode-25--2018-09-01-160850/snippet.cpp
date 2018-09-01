// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (32.97%)
 * Total Accepted:    139.1K
 * Total Submissions: 421.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 *
 *
 *
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 */

#ifdef CC_PLAYGROUND
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto* pp = &head;
        for (;;) {
            auto p = *pp, q = p;
            int i;
            for (i = 0; i < k && q != nullptr; i++)
                q = q->next;
            if (i == k) {
                auto p = *pp, l = p;
                auto npp = &p->next;
                while (p != q) {
                    auto np = p->next;
                    p->next = l;
                    l = p;
                    p = np;
                }
                *npp = q;
                *pp = l;
                pp = npp;
            } else {
                return head;
            }
        }
    }
};

int mymain(int argc, char* argv[]) { return 0; }
