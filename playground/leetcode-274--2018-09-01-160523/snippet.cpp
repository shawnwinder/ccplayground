// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [274] H-Index
 *
 * https://leetcode.com/problems/h-index/description/
 *
 * algorithms
 * Medium (34.12%)
 * Total Accepted:    106K
 * Total Submissions: 310.8K
 * Testcase Example:  '[3,0,6,1,5]'
 *
 * Given an array of citations (each citation is a non-negative integer) of a
 * researcher, write a function to compute the researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: "A scientist has index
 * h if h of his/her N papers have at least h citations each, and the other N -
 * h papers have no more than h citations each."
 *
 * Example:
 *
 *
 * Input: citations = [3,0,6,1,5]
 * Output: 3
 * Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each
 * of them had
 *             received 3, 0, 6, 1, 5 citations respectively.
 * Since the researcher has 3 papers with at least 3 citations each and the
 * remaining
 * two with no more than 3 citations each, her h-index is 3.
 *
 * Note: If there are several possible values for h, the maximum one is taken
 * as the h-index.
 *
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> b(n + 1);
        for (int i : citations) {
            if (i > n)
                i = n;
            b[i]++;
        }
        int cnt = 0;
        for (int i = n; i >= 0; i--) {
            cnt += b[i];
            if (cnt >= i)
                return i;
        }
        return 0;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
