// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [275] H-Index II
 *
 * https://leetcode.com/problems/h-index-ii/description/
 *
 * algorithms
 * Medium (35.05%)
 * Total Accepted:    68.7K
 * Total Submissions: 196.1K
 * Testcase Example:  '[0,1,3,5,6]'
 *
 * Given an array of citations sorted in ascending order (each citation is a
 * non-negative integer) of a researcher, write a function to compute the
 * researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: "A scientist has index
 * h if h of his/her N papers have at least h citations each, and the other N -
 * h papers have no more than h citations each."
 *
 * Example:
 *
 *
 * Input: citations = [0,1,3,5,6]
 * Output: 3
 * Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each
 * of them had
 *             received 0, 1, 3, 5, 6 citations respectively.
 * Since the researcher has 3 papers with at least 3 citations each and the
 * remaining
 * two with no more than 3 citations each, her h-index is 3.
 *
 * Note:
 *
 * If there are several possible values for h, the maximum one is taken as the
 * h-index.
 *
 * Follow up:
 *
 *
 * This is a follow up problem to H-Index, where citations is now guaranteed to
 * be sorted in ascending order.
 * Could you solve it in logarithmic time complexity?
 *
 *
 */
class Solution {
public:
    int hIndex(vector<int> citations) {
        int n = citations.size();
        int lo = 0, hi = n-1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // find the first citations[i] >= n-i
            if (citations[mid] >= n - mid) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return n-lo;
    }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
