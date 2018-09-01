// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (27.01%)
 * Total Accepted:    175K
 * Total Submissions: 648.2K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Example:
 *
 *
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 *
 *
 */
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> p(n, true);
        p[0] = p[1] = false;
        for (int i = 2; i < sqrt(n); i++) {
            if (p[i]) {
                for (int j = i * i; j < n; j += i)
                    p[j] = false;
            }
        }
        return count(p.begin(), p.end(), true);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
