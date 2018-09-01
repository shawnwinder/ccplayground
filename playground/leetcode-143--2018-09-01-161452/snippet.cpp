// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <stack>

using namespace std;

/*
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (27.84%)
 * Total Accepted:    122K
 * Total Submissions: 438.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0->L1->...->Ln-1->Ln,
 * reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 * Example 1:
 *
 *
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 *
 * Example 2:
 *
 *
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* node;
        if (!head || !head->next || !head->next->next)
            return;
        node = head;
        while (node) {
            s.push(node);
            node = node->next;
        }
        node = head;
        while (node != s.top() && node->next != s.top()) {
            s.top()->next = node->next;
            node->next = s.top();
            s.pop();
            node = node->next->next;
        }
        if (node == s.top())
            node->next = NULL;
        else
            node->next->next = NULL;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
