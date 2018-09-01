// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (25.24%)
 * Total Accepted:    68.2K
 * Total Submissions: 270.3K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 *
 * Example 1:
 *
 *
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
 * 3.
 *
 *
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2) return 0;
        using pp=pair<int, int>;
        vector<pp> s;
        int l = 0;
        int r = 1;
        vector<int> t;
        while (r < prices.size()) {
            int last = prices[l];
            pp c;
            while (r < prices.size() && last <= prices[r]) {
                last = prices[r];
                r ++;
            }
            if (r - 1 > l) {
                c = {prices[l], prices[r-1]} ;
                while (!s.empty() && c.first  <= s.back().first) {
                  auto c2 = s.back();
                  s.pop_back();
                  t.push_back(c2.second - c2.first);
                }
                while (!s.empty() && c.second >= s.back().second) {
                    auto c2 = s.back();
                    s.pop_back();
                    t.push_back(c2.second - c.first);
                    c.first = c2.first;
                }
                s.push_back(c);
            }
            l = r;
            r ++;
        }
        for (auto& p:s) {
            t.push_back(p.second - p.first);
        }
        k = min(t.size(), (size_t)k);
        nth_element(t.begin(), t.begin() + k, t.end(), greater<int>());
        return accumulate(t.begin(), t.begin() + k, 0);
    }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
