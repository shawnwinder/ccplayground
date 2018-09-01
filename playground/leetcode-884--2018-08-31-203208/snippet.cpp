// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

/*
 * [920] Uncommon Words from Two Sentences
 *
 * https://leetcode.com/problems/uncommon-words-from-two-sentences/description/
 *
 * algorithms
 * Easy (61.12%)
 * Total Accepted:    7.8K
 * Total Submissions: 12.9K
 * Testcase Example:  '"this apple is sweet"\n"this apple is sour"'
 *
 * We are given two sentences A and B.  (A sentence is a string of space
 * separated words.  Each word consists only of lowercase letters.)
 *
 * A word is uncommon if it appears exactly once in one of the sentences, and
 * does not appear in the other sentence.
 *
 * Return a list of all uncommon words. 
 *
 * You may return the list in any order.
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
 * Input: A = "this apple is sweet", B = "this apple is sour"
 * Output: ["sweet","sour"]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: A = "apple apple", B = "banana"
 * Output: ["banana"]
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= A.length <= 200
 * 0 <= B.length <= 200
 * A and B both contain only spaces and lowercase letters.
 *
 *
 *
 */
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> count;
        istringstream iss(A + " " + B);
        while (iss >> A)
            count[A]++;
        vector<string> res;
        for (auto w : count)
            if (w.second == 1)
                res.push_back(w.first);
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }


int mymain(int argc, char* argv[]) { return 0; }
