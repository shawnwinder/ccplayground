// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [632] Smallest Range
 *
 * https://leetcode.com/problems/smallest-range/description/
 *
 * algorithms
 * Hard (43.27%)
 * Total Accepted:    13.1K
 * Total Submissions: 30.2K
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * You have k lists of sorted integers in ascending order. Find the smallest
 * range that includes at least one number from each of the k lists.
 *
 * We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c
 * if b-a == d-c.
 *
 * Example 1:
 *
 * Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
 * Output: [20,24]
 * Explanation:
 * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 * List 2: [0, 9, 12, 20], 20 is in range [20,24].
 * List 3: [5, 18, 22, 30], 22 is in range [20,24].
 *
 *
 *
 *
 * Note:
 *
 * The given list may contain duplicates, so ascending order means >= here.
 * 1 k
 * -105 value of elements 5.
 * For Java users, please note that the input type has been changed to
 * List<List<Integer>>. And after you reset the code template, you'll see this
 * point.
 *
 *
 *
 */
 class Solution {
 public:
   vector<int> smallestRange(vector<vector<int>>& nums) {
       using pp=pair<vector<int>::iterator, vector<int>::iterator>;
       struct cmp {
           bool operator()(const pp& l, const pp& r) {
               return *l.first > *r.first;
           } 
       };
       priority_queue<pp, vector<pp>, cmp> pq;
       int lo = INT_MAX;
       int hi = INT_MIN;
       
       for (auto& v : nums) {
           lo = min(lo, v[0]);
           hi = max(hi, v[0]);
           pq.push({v.begin(), v.end()});
       }
       
       
       vector<int> ret = {lo, hi};
       while (true) {
           pp x = pq.top();
           if (++x.first == x.second) break;
           pq.pop();
           pq.push(x);
           hi = max(hi, *x.first);
           
           lo = *pq.top().first;
           
           if ( hi - lo < ret[1] - ret[0]) {
               ret = {lo, hi};
           }
       }
       return ret;
   }    
 };


int mymain(int argc, char *argv[]) {
    return 0;
}
