// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
 * [901] Advantage Shuffle
 *
 * https://leetcode.com/problems/advantage-shuffle/description/
 *
 * algorithms
 * Medium (39.49%)
 * Total Accepted:    4.8K
 * Total Submissions: 12.2K
 * Testcase Example:  '[2,7,11,15]\n[1,10,4,11]'
 *
 * Given two arrays A and B of equal size, the advantage of A with respect to B
 * is the number of indices i for which A[i] > B[i].
 *
 * Return any permutation of A that maximizes its advantage with respect to
 * B.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: A = [2,7,11,15], B = [1,10,4,11]
 * Output: [2,11,7,15]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: A = [12,24,8,32], B = [13,25,32,11]
 * Output: [24,32,8,12]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length = B.length <= 10000
 * 0 <= A[i] <= 10^9
 * 0 <= B[i] <= 10^9
 *
 *
 *
 */
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(begin(A), end(A));
        for (auto i = 0; i < B.size(); ++i) {
            auto p = *s.rbegin() <= B[i] ? s.begin() : s.upper_bound(B[i]);
            A[i] = *p;
            s.erase(p);
        }
        return A;
    }
};

int mymain(int argc, char* argv[]) { return 0; }


int mymain(int argc, char* argv[]) { return 0; }
