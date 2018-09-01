// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (29.88%)
 * Total Accepted:    259.7K
 * Total Submissions: 869.2K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Example:
 *
 *
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 *
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode pre(0), *h = &pre;
        ListNode* l = h;
        auto cmp = [](ListNode* l, ListNode* r) { return l->val > r->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto& x : lists) {
            if (x != NULL) {
                pq.push(x);
            }
        }
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            if (v->next != NULL) {
                pq.push(v->next);
            }
            l->next = new ListNode(v->val);
            l = l->next;
        }
        return h->next;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
