// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (34.75%)
 * Total Accepted:    289K
 * Total Submissions: 831.7K
 * Testcase Example:  '[]\nno cycle'
 *
 *
 * Given a linked list, determine if it has a cycle in it.
 *
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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        auto fast = head;
        auto slow = head;
        while (slow->next && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
