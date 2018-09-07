// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

/*
 * [903] Implement Rand10() Using Rand7()
 *
 * https://leetcode.com/problems/implement-rand10-using-rand7/description/
 *
 * algorithms
 * Medium (42.99%)
 * Total Accepted:    2.5K
 * Total Submissions: 5.9K
 * Testcase Example:  '1'
 *
 * Given a function rand7 which generates a uniform random integer in the range
 * 1 to 7, write a function rand10 which generates a uniform random integer in
 * the range 1 to 10.
 *
 * Do NOT use system's Math.random().
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: [7]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 2
 * Output: [8,4]
 *
 *
 *
 * Example 3:
 *
 *
 * Input: 3
 * Output: [8,1,10]
 *
 *
 *
 *
 * Note:
 *
 *
 * rand7 is predefined.
 * Each testcase has one argument: n, the number of times that rand10 is
 * called.
 *
 *
 *
 *
 * Follow up:
 *
 *
 * What is the expected value for the number of calls to rand7() function?
 * Could you minimize the number of calls to rand7()?
 *
 *
 *
 *
 *
 */
// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
    stack<int> cache;
    constexpr static int N = 19;

    void generate() {
        long cur = 0, range = long(pow(7, N));
        for (int i = 0; i < N; ++i)
            cur += long(pow(7, i)) * (rand7() - 1);
        while (cur < range / 10 * 10) {
            cache.push(cur % 10 + 1);
            cur /= 10;
            range /= 10;
        }
    }

public:
    int rand10() {
        while (cache.size() == 0)
            generate();
        int res = cache.top();
        cache.pop();
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
