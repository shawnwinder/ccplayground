// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (34.67%)
 * Total Accepted:    25.6K
 * Total Submissions: 73.9K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 *
 * Given a sorted array, two integers k and x, find the k closest elements to x
 * in the array.  The result should also be sorted in ascending order.
 * If there is a tie,  the smaller elements are always preferred.
 *
 *
 * Example 1:
 *
 * Input: [1,2,3,4,5], k=4, x=3
 * Output: [1,2,3,4]
 *
 *
 *
 *
 * Example 2:
 *
 * Input: [1,2,3,4,5], k=4, x=-1
 * Output: [1,2,3,4]
 *
 *
 *
 * Note:
 *
 * The value k is positive and will always be smaller than the length of the
 * sorted array.
 * Length of the given array is positive and will not exceed 104
 * Absolute value of elements in the array and x will not exceed 104
 *
 *
 *
 *
 *
 *
 * UPDATE (2017/9/19):
 * The arr parameter had been changed to an array of integers (instead of a
 * list of integers). Please reload the code definition to get the latest
 * changes.
 *
 */
 class Solution {
 public:
   vector<int> findClosestElements(vector<int>& arr, int k, int x) {
     auto i = lower_bound(arr.begin(), arr.end(), x);
     if (i == arr.end()) {
       return vector<int>(arr.end() - k, arr.end());
     }
     if (i == arr.begin()) {
       return vector<int>(arr.begin(), arr.begin() + k);
     }
     auto j = i-1;
     for (int c = 0; c < k; c++) {
       if (j < arr.begin()) i++;
       else if (i >= arr.end()) j--;
       else if ( x - *j <= *i -x ) j--; else i++;
     }
     return vector<int>(j+1, i);
   }
 };



int mymain(int argc, char *argv[]) {
    return 0;
}
