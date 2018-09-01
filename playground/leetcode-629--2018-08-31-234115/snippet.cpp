// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [629] K Inverse Pairs Array
 *
 * https://leetcode.com/problems/k-inverse-pairs-array/description/
 *
 * algorithms
 * Hard (27.82%)
 * Total Accepted:    5.8K
 * Total Submissions: 20.9K
 * Testcase Example:  '3\n0'
 *
 *
 * Given two integers n and k, find how many different arrays consist of
 * numbers from 1 to n such that there are exactly k inverse pairs.
 *
 *
 * We define an inverse pair as following:
 * For ith and jth element in the array, if i < j and a[i] > a[j] then it's an
 * inverse pair; Otherwise, it's not.
 *
 *
 *
 * Since the answer may be very large, the answer should be modulo 109 + 7.
 *
 *
 * Example 1:
 *
 * Input: n = 3, k = 0
 * Output: 1
 * Explanation:
 * Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0
 * inverse pair.
 *
 *
 *
 * Example 2:
 *
 * Input: n = 3, k = 1
 * Output: 2
 * Explanation:
 * The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
 *
 *
 *
 * Note:
 *
 * The integer n is in the range [1, 1000] and k is in the range [0, 1000].
 *
 *
 */
 class Solution {
 public:
   int kInversePairs(int n, int k) {
     vector<vector<long long>> ans(k+1, vector<long long>(n));
     for (int i = 0; i<n; i ++ ) {
       ans[0][i] = 1;
     }
     for (int i = 0; i<=k; i ++ ) {
       ans[i][0] = 1;
     }
     for (int i = 1; i<=k; i++) {
       for (int j = 1; j<=n-1; j++) {
         int x = i - j - 1;
         long long d = 0;
         if (x >= 0) d = ans[x][j-1];
         ans[i][j] = (ans[i][j-1] - d + ans[i-1][j]) % (1000000000 + 7);
       }
     }
     return (ans[k][n-1] + 1000000000 + 7 - ( (k == 0)?0:ans[k-1][n-1] )) % (1000000000 + 7);

   }
 };


int mymain(int argc, char *argv[]) {
    return 0;
}
