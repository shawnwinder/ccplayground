// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (30.05%)
 * Total Accepted:    54.5K
 * Total Submissions: 181.4K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itinerary in order. All of the
 * tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 * with JFK.
 *
 * Note:
 *
 *
 * If there are multiple valid itineraries, you should return the itinerary
 * that has the smallest lexical order when read as a single string. For
 * example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 *
 *
 * Example 1:
 *
 *
 * Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"].
 * But it is larger in lexical order.
 *
 *
 */
class Solution {
public:
    // Hierholzer
    vector<string> findItinerary(vector<pair<string, string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for (auto& x : tickets)
            m[x.first].insert(x.second);
        stack<string> st;
        vector<string> ret;
        st.push("JFK");
        while (!st.empty()) {
            auto& x = st.top();
            if (m[x].empty()) {
                ret.push_back(x);
                st.pop();
            } else {
                auto it = m[x].begin();
                st.push(*it);
                m[x].erase(it);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
