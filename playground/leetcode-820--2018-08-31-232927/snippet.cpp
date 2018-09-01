// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [839] Short Encoding of Words
 *
 * https://leetcode.com/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (43.61%)
 * Total Accepted:    4.5K
 * Total Submissions: 10.4K
 * Testcase Example:  '["time", "me", "bell"]'
 *
 * Given a list of words, we may encode it by writing a reference string S and
 * a list of indexes A.
 *
 * For example, if the list of words is ["time", "me", "bell"], we can write it
 * as S = "time#bell#" and indexes = [0, 2, 5].
 *
 * Then for each index, we will recover the word by reading from the reference
 * string from that index until we reach a "#" character.
 *
 * What is the length of the shortest reference string S possible that encodes
 * the given words?
 *
 * Example:
 *
 *
 * Input: words = ["time", "me", "bell"]
 * Output: 10
 * Explanation: S = "time#bell#" and indexes = [0, 2, 5].
 *
 *
 * Note:
 *
 *
 * 1 <= words.length <= 2000.
 * 1 <= words[i].length <= 7.
 * Each word has only lowercase letters.
 *
 *
 */
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {

    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
