// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (34.06%)
 * Total Accepted:    83.1K
 * Total Submissions: 244.1K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 *
 * Example:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note:  
 *
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 *
 *
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};
        vector<int> idx(primes.size(), 0);
        vector<int> u(n, INT_MAX);
        u[0] = 1;
        for (int i=1;i<n;i++) {
            int k = -1;
            for (int j=0;j<primes.size();j++) {
                u[i] = min(u[i], u[idx[j]] * primes[j]);
            }
            for (int j=0;j<primes.size();j++) {
                idx[j] += (u[i] == u[idx[j]] * primes[j]);
            }
        }
        return u.back();
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
