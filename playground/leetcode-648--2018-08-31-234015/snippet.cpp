// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [648] Replace Words
 *
 * https://leetcode.com/problems/replace-words/description/
 *
 * algorithms
 * Medium (48.95%)
 * Total Accepted:    22.1K
 * Total Submissions: 45.1K
 * Testcase Example:  '["cat", "bat", "rat"]\n"the cattle was rattled by the battery"'
 *
 *
 * In English, we have a concept called root, which can be followed by some
 * other words to form another longer word - let's call this word successor.
 * For example, the root an, followed by other, which can form another word
 * another.
 *
 *
 *
 *
 * Now, given a dictionary consisting of many roots and a sentence. You need to
 * replace all the successor in the sentence with the root forming it. If a
 * successor has many roots can form it, replace it with the root with the
 * shortest length.
 *
 *
 *
 * You need to output the sentence after the replacement.
 *
 *
 *
 * Example 1:
 *
 * Input: dict = ["cat", "bat", "rat"]
 * sentence = "the cattle was rattled by the battery"
 * Output: "the cat was rat by the bat"
 *
 *
 *
 *
 * Note:
 *
 * The input will only have lower-case letters.
 * ⁠1
 * ⁠1
 * ⁠1
 * ⁠1
 *
 *
 */
class Solution {
public:

    string replaceWords(vector<string>& dict, string sentence) {
        Node* root = new Node();
        for (auto& s : dict) {
            root->add(s);
        }
        stringstream ss(sentence);
        string s;
        stringstream ret;
        while (ss >> s) {
            ret << root->get(s) << " ";
        }
        string ans = ret.str();
        ans.pop_back();
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
