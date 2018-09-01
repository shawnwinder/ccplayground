// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (37.84%)
 * Total Accepted:    270.9K
 * Total Submissions: 715.9K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */
class Solution {
public:
    // Initial state:

    // - result = {""}

    // Stage 1 for number "1":

    // - result has {""}
    // - candiate is "abc"
    // - generate three strings "" + "a", ""+"b", ""+"c" and put into tmp,
    //   tmp = {"a", "b", "c"}
    // - swap result and tmp (swap does not take memory copy)
    // - Now result has {"a", "b", "c"}

    // Stage 2 for number "2":

    // - result has {"a", "b", "c"}
    // - candidate is "def"
    // - generate nine strings and put into tmp,
    //    "a" + "d", "a"+"e", "a"+"f",
    //    "b" + "d", "b"+"e", "b"+"f",
    //    "c" + "d", "c"+"e", "c"+"f"
    // - so tmp has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
    // - swap result and tmp
    // - Now result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }

    // Stage 3 for number "3":

    // - result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
    // - candidate is "ghi"
    // - generate 27 strings and put into tmp,
    // -  add "g" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
    // -  add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
    // -  add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
    // - so, tmp has
    //             {"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
    //              "adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
    //              "adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
    // - swap result and tmp
    // - Now result has
    //             {"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
    //              "adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
    //              "adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty())
            return vector<string>();
        static const vector<string> v
            = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        result.push_back(""); // add a seed for the initial case
        for (int i = 0; i < digits.size(); ++i) {
            int num = digits[i] - '0';
            if (num < 0 || num > 9)
                break;
            const string& candidate = v[num];
            if (candidate.empty())
                continue;
            vector<string> tmp;
            for (int j = 0; j < candidate.size(); ++j) {
                for (int k = 0; k < result.size(); ++k) {
                    tmp.push_back(result[k] + candidate[j]);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
