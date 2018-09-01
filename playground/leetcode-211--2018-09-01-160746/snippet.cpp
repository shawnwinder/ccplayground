// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <memory>

using namespace std;

/*
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (26.70%)
 * Total Accepted:    85.3K
 * Total Submissions: 319.6K
 * Testcase Example:
 * '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports the following two operations:
 *
 *
 * void addWord(word)
 * bool search(word)
 *
 *
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 *
 * Example:
 *
 *
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 *
 *
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 *
 */
struct TrieNode {
    bool isKey;
    unique_ptr<TrieNode> children[26];
    TrieNode()
        : isKey(false) {}
};

class WordDictionary {
public:
    WordDictionary()
        : root(new TrieNode()) {}

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* run = root.get();
        for (char c : word) {
            if (!(run->children[c - 'a']))
                run->children[c - 'a'].reset(new TrieNode());
            run = run->children[c - 'a'].get();
        }
        run->isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) { return query(word.c_str(), root.get()); }

private:
    unique_ptr<TrieNode> root;
    bool query(const char* word, TrieNode* node) {
        TrieNode* run = node;
        for (int i = 0; word[i]; i++) {
            if (run && word[i] != '.')
                run = run->children[word[i] - 'a'].get();
            else if (run && word[i] == '.') {
                TrieNode* tmp = run;
                for (int j = 0; j < 26; j++) {
                    run = tmp->children[j].get();
                    if (query(word + i + 1, run))
                        return true;
                }
            } else
                break;
        }
        return run && run->isKey;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int mymain(int argc, char* argv[]) { return 0; }
