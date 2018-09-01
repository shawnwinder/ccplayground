// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (30.77%)
 * Total Accepted:    220K
 * Total Submissions: 715K
 * Testcase Example:  'No intersection: []\n[]'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:           a1 -> a2
 *                    |
 *                    |-> c1 -> c2 -> c3
 *                    |
 * B:     b1 -> b2 -> b3
 *
 * begin to intersect at node c1.
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
 *
 *
 * Credits:Special thanks to @stellari for adding this problem and creating all
 * test cases.
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        if (p1 == NULL || p2 == NULL)
            return NULL;
        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            // Any time they collide or reach end together without colliding
            // then return any one of the pointers.
            if (p1 == p2)
                return p1;
            // If one of them reaches the end earlier then reuse it
            // by moving it to the beginning of other list.
            // Once both of them go through reassigning,
            // they will be equidistant from the collision point.
            if (p1 == NULL)
                p1 = headB;
            if (p2 == NULL)
                p2 = headA;
        }
        return p1;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
