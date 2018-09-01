// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (31.46%)
 * Total Accepted:    146.4K
 * Total Submissions: 465.5K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * Example 1:
 *
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 *
 *
 * Example 2:
 *
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode pre(0), *p = &pre;
        while (head1 || head2) {
            if (head1 && (!head2 || head1->val <= head2->val)) {
                p = p->next = head1;
                head1 = head1->next;
            }
            if (head2 && (!head1 || head2->val < head1->val)) {
                p = p->next = head2;
                head2 = head2->next;
            }
        }
        p->next = NULL;
        return pre.next;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* headb = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(headb));
    }
};

int mymain(int argc, char* argv[]) { return 0; }
