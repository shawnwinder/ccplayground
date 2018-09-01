// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

/*
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (30.39%)
 * Total Accepted:    111.3K
 * Total Submissions: 365.5K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 *
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 *
 * Given n and k, return the kth permutation sequence.
 *
 * Note:
 *
 *
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, k = 3
 * Output: "213"
 *
 *
 * Example 2:
 *
 *
 * Input: n = 4, k = 9
 * Output: "2314"
 *
 *
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        int i, j, fact = 1;
        string s(n, '0');
        for (i = 1; i <= n; i++) {
            fact *= i;
            s[i - 1] += i;
        }
        for (i = 0, k--; i < n; i++) {
            fact /= n - i;
            j = i + k / fact; // calculate index of char to put at s[i]
            char c = s[j];
            // remove c by shifting to cover up (adjust the right part).
            for (; j > i; j--)
                s[j] = s[j - 1];
            k %= fact;
            s[i] = c;
        }
        return s;
    }
};

int mymain(int argc, char* argv[]) {
    Solution s;
    std::cout << s.getPermutation(5, 2) << std::endl;
    return 0;
}
