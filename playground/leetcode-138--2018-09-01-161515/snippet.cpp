// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.71%)
 * Total Accepted:    175K
 * Total Submissions: 680.9K
 * Testcase Example:  '{}'
 *
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 *
 *
 * Return a deep copy of the list.
 *
 */

#ifdef CC_PLAYGROUND
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x)
        : label(x)
        , next(NULL)
        , random(NULL) {}
};
#endif

class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        RandomListNode *newHead, *l1, *l2;
        if (head == NULL)
            return NULL;
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->random;
            l1->random = l2;
        }
        newHead = head->random;
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->random;
            l2->random = l2->next ? l2->next->random : NULL;
        }
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : NULL;
        }
        return newHead;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
