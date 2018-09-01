// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (34.13%)
 * Total Accepted:    172.5K
 * Total Submissions: 505.4K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example:
 *
 *
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head, *op = new ListNode(0);
        op->next = p;
        head = op;
        while(p) {
            if(p->val == val) {
                op->next = p->next;
                delete p;
                p = op->next;
            } else {
                op = p;
                p = p->next;
            }
        }
        return head->next;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
