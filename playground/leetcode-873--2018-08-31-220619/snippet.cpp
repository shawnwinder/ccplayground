// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [905] Length of Longest Fibonacci Subsequence
 *
 * https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
 *
 * algorithms
 * Medium (41.23%)
 * Total Accepted:    4.7K
 * Total Submissions: 11.6K
 * Testcase Example:  '[1,2,3,4,5,6,7,8]'
 *
 * A sequence X_1, X_2, ..., X_n is fibonacci-like if:
 *
 *
 * n >= 3
 * X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
 *
 *
 * Given a strictly increasing array A of positive integers forming a sequence,
 * find the length of the longest fibonacci-like subsequence of A.  If one does
 * not exist, return 0.
 *
 * (Recall that a subsequence is derived from another sequence A by deleting
 * any number of elements (including none) from A, without changing the order
 * of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3,
 * 4, 5, 6, 7, 8].)
 *
 * Example 1:
 *
 *
 * Input: [1,2,3,4,5,6,7,8]
 * Output: 5
 * Explanation:
 * The longest subsequence that is fibonacci-like: [1,2,3,5,8].
 *
 *
 * Example 2:
 *
 *
 * Input: [1,3,7,11,12,14,18]
 * Output: 3
 * Explanation:
 * The longest subsequence that is fibonacci-like:
 * [1,11,12], [3,11,14] or [7,11,18].
 *
 * Note:
 *
 *
 * 3 <= A.length <= 1000
 * 1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
 * (The time limit has been reduced by 50% for submissions in Java, C, and
 * C++.)
 *
 */
class Solution {
public:
    // `dp[a, b]` represents the length of fibo sequence ends up with `(a, b)`
    // Then we have `dp[a, b] = dp[b - a, a] or 2`
    // The complexity reduce to `O(N^2)`.
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int, int> m;
        int N = A.size(), res = 0;
        int dp[N][N];
        for (int j = 0; j < N; ++j) {
            m[A[j]] = j;
            for (int i = j; i-- > 0;) {
                int k = m.find(A[j] - A[i]) == m.end() ? N : m[A[j] - A[i]];
                dp[i][j] = k < i ? dp[k][i] + 1 : 2;
                res = max(res, dp[i][j]);
            }
        }
        return res > 2 ? res : 0;
    }
};

int mymain(int argc, char* argv[]) { return 0; }


int mymain(int argc, char* argv[]) { return 0; }
