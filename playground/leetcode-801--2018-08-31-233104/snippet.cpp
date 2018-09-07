// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [819] Minimum Swaps To Make Sequences Increasing
 *
 * https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
 *
 * algorithms
 * Medium (31.81%)
 * Total Accepted:    7.7K
 * Total Submissions: 24.2K
 * Testcase Example:  '[1,3,5,4]\n[1,2,3,7]'
 *
 * We have two integer sequences A and B of the same non-zero length.
 *
 * We are allowed to swap elements A[i] and B[i].  Note that both elements are
 * in the same index position in their respective sequences.
 *
 * At the end of some number of swaps, A and B are both strictly increasing.
 * (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... <
 * A[A.length - 1].)
 *
 * Given A and B, return the minimum number of swaps to make both sequences
 * strictly increasing.  It is guaranteed that the given input always makes it
 * possible.
 *
 *
 * Example:
 * Input: A = [1,3,5,4], B = [1,2,3,7]
 * Output: 1
 * Explanation:
 * Swap A[3] and B[3].  Then the sequences are:
 * A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
 * which are both strictly increasing.
 *
 *
 * Note:
 *
 *
 * A, B are arrays with the same length, and that length will be in the range
 * [1, 1000].
 * A[i], B[i] are integer values in the range [0, 2000].
 *
 */
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> not_swap(n, n);
        vector<int> swap(n, n);
        not_swap[0] = 0;
        swap[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                not_swap[i] = not_swap[i - 1];
                swap[i] = swap[i - 1] + 1;
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                not_swap[i] = min(not_swap[i], swap[i - 1]);
                swap[i] = min(swap[i], not_swap[i - 1] + 1);
            }
        }
        return min(swap.back(), not_swap.back());
    }
};

int mymain(int argc, char* argv[]) { return 0; }
