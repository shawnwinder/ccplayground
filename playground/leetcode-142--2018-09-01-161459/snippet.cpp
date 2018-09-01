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
    ListNode *detectCycle(ListNode *head) {
        auto f = head, s = head;
        while (f && f->next) {
            f = f->next->next;
            s = s->next;
            if (f == s) break;
        }
        if (!f || !f->next) return nullptr;
        while (head != f) {
            head = head->next;
            f = f->next;
        }
        return f;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
