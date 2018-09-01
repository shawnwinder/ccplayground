// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <memory>

using namespace std;

/*
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (33.07%)
 * Total Accepted:    129.5K
 * Total Submissions: 391.6K
 * Testcase Example:
 * '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Example:
 *
 *
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");
 * trie.search("app");     // returns true
 *
 *
 * Note:
 *
 *
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 *
 *
 */
struct TrieNode {
public:
    unique_ptr<TrieNode> next[26];
    bool is_word;
    TrieNode(bool b = false) { is_word = b; }
};

class Trie {
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* p = root;
        for (int i = 0; i < s.size(); ++i) {
            if (p->next[s[i] - 'a'] == nullptr)
                p->next[s[i] - 'a'].reset(new TrieNode());
            p = p->next[s[i] - 'a'].get();
        }
        p->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* p = find(key);
        return p != nullptr && p->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) { return find(prefix) != nullptr; }

private:
    TrieNode* find(string key) {
        TrieNode* p = root;
        for (int i = 0; i < key.size() && p != nullptr; ++i)
            p = p->next[key[i] - 'a'].get();
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int mymain(int argc, char* argv[]) { return 0; }
