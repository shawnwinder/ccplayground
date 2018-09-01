// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (42.65%)
 * Total Accepted:    45.6K
 * Total Submissions: 106.9K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks.Tasks could
 * be done without original order. Each task could be done in one interval. For
 * each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 *
 * Example 1:
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 *
 *
 *
 * Note:
 *
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 *
 *
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0 || tasks.empty()) return tasks.size();
        unordered_map<char, int> m;
        for (char t : tasks) {
            m[t] ++;
        }
        vector<int> c;
        transform(m.begin(), m.end(), back_inserter(c), [](pair<char, int> e) {
            return e.second;
        });
        sort(c.begin(), c.end(), greater<int>());
        int idle = (c[0] - 1) * (n + 1);
        for (auto x: c) {
            idle -= min(x, c[0] - 1);
        }
        return idle > 0 ? idle + tasks.size() : tasks.size();
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
