// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (42.59%)
 * Total Accepted:    69.7K
 * Total Submissions: 163.6K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 *
 *
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 *
 *
 * Example:
 *
 *
 * Input: [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 *
 *
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() <= 1) return 0;
        int buy = -prices[0];
        int hold = -prices[0];
        int sell = 0;
        int empty = 0;
        
        for (int i=1;i<prices.size();i++) {
            hold = max(buy, hold);            
            buy = empty - prices[i];
            empty = max(empty, sell);
            sell = hold + prices[i];
        }
        return max(sell, empty);
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
