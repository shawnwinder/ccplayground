// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <sstream>

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
 * Given k will be between 1 and n! inclusive.
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
        std::vector<int> w(n);
        std::iota(w.begin(), w.end(), 1);
        for (auto i = 0u; i < k-1; ++i) {
            std::next_permutation(w.begin(), w.end());
        }
        std::stringstream ss;
        for (auto e : w) {
            ss << e;
        }
        return ss.str();
    }
};

int mymain(int argc, char *argv[]) {
    Solution s;
    std::cout << s.getPermutation(5, 2) << std::endl;
    return 0;
}


int mymain(int argc, char *argv[]) {
    Solution s;
    std::cout << s.getPermutation(5, 2) << std::endl;
    return 0;
}
