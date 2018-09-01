// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (32.33%)
 * Total Accepted:    152.3K
 * Total Submissions: 471.1K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return nullptr;
        auto *pp=&head;
        n -= m-1;
        while (--m) pp=&(*pp)->next;
        auto q=*pp, l=q, e=q;
        while (n--) {
            auto nq = q->next;
            q->next = l;
            l = q;
            q = nq;
        }
        e->next = q;
        *pp = l;
        return head;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
