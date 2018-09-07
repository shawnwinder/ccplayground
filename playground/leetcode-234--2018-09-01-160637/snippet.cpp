// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (34.13%)
 * Total Accepted:    185.9K
 * Total Submissions: 544.7K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Example 1:
 *
 *
 * Input: 1->2
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: 1->2->2->1
 * Output: true
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode* one = head;
        ListNode* two = head;
        while (two->next && two->next->next) {
            one = one->next;
            two = two->next->next;
        }
        two = one->next;
        one = head;
        ListNode* p = two->next;
        ListNode* q;
        two->next = NULL;
        while (p != NULL) {
            q = p;
            p = p->next;
            q->next = two;
            two = q;
        }
        while (two && two->val == one->val) {
            two = two->next;
            one = one->next;
        }
        return two == NULL;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
