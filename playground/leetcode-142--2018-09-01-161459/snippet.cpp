// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (30.05%)
 * Total Accepted:    165.2K
 * Total Submissions: 549.9K
 * Testcase Example:  '[]\nno cycle'
 *
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 *
 *
 *
 * Note: Do not modify the linked list.
 *
 *
 * Follow up:
 * Can you solve it without using extra space?
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
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        auto slow = head;
        auto fast = head;
        auto entry = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // there is a cycle
                while (slow != entry) { // found the entry location
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL; // there has no cycle
    }
};

int mymain(int argc, char* argv[]) { return 0; }
