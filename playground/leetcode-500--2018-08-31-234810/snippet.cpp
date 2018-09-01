// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (60.47%)
 * Total Accepted:    70.7K
 * Total Submissions: 116.9K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below.
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 *
 *
 *
 * Note:
 *
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 *
 *
 */
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for (int i=0; i<words.size(); i++) {
            int l1 = 0;
            int l2 = 0;
            int l3 = 0;
            
            for (char c : words[i]) {
                
            c = tolower(c);
        
        switch (c) {
            case 'q':
            case 'w':
            case 'e':
            case 'r':
            case 't':
            case 'y':
            case 'u':
            case 'i':
            case 'o':
            case 'p':
                l1 = 1;
                break;
            case 'a':
            case 's':
            case 'd':
            case 'f':
            case 'g':
            case 'h':
            case 'j':
            case 'k':
            case 'l':
                l2 = 1;
                break;
            case 'z':
            case 'x':
            case 'c':
            case 'v':
            case 'b':
            case 'n':
            case 'm':
                l3 = 1;
                break;
        }
            }
            if (l1 + l2 + l3 == 1) ans.push_back(words[i]);
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
