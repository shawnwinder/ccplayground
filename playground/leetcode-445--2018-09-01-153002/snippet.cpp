// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (47.11%)
 * Total Accepted:    59.4K
 * Total Submissions: 126K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 *
 *
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        deque<int> a, b;
        vector<int> c;
        while (l1) {
            a.push_front(l1->val);
            l1=l1->next;
        }
        while (l2) {
            b.push_front(l2->val);
            l2=l2->next;
        }
        int i, j, k=0;
        for (i = 0, j = 0; i<a.size() && j<b.size(); i++, j++) {
            int sum = a[i] + b[i] + k;
            k = sum / 10;
            c.push_back(sum % 10);
        }
        for (;i<a.size();i++) {
            int sum = a[i] + k;
            k = sum / 10;
            c.push_back(sum % 10);
        }
        for (;j<b.size();j++) {
            int sum = b[j] + k;
            k = sum / 10;
            c.push_back(sum % 10);
        }
        if (k > 0) c.push_back(k);
        
        
        ListNode * ret = nullptr;
        for (int x : c) {
            ListNode * nn = new ListNode(x);
            nn->next = ret;
            ret = nn;
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
