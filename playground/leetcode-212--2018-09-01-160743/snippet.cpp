// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (25.72%)
 * Total Accepted:    75.9K
 * Total Submissions: 295.1K
 * Testcase Example:
 * '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 *
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 *
 * Example:
 *
 *
 * Input:
 * words = ["oath","pea","eat","rain"] and board =
 * [
 *  ['o','a','a','n'],
 *  ['e','t','a','e'],
 *  ['i','h','k','r'],
 *  ['i','f','l','v']
 * ]
 *
 * Output: ["eat","oath"]
 *
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 */
struct Trie {
    Trie* children[26];
    bool isLeaf;
    int wordIdx;
    int prefixCount;
    Trie() {
        isLeaf = false;
        wordIdx = 0;
        prefixCount = 0;
        fill_n(children, sizeof(children), nullptr);
    }
    ~Trie() {
        for (auto i = 0; i < sizeof(children); ++i)
            delete children[i];
    }
};

class Solution {
private:
    void insertWord(Trie* root, const vector<string>& words, int idx) {
        int i, childID, len = words[idx].size();
        for (i = 0, root->prefixCount++; i < len; ++i) {
            childID = words[idx][i] - 'a';
            if (!root->children[childID])
                root->children[childID] = new Trie();
            root = root->children[childID];
            ++root->prefixCount;
        }
        root->isLeaf = true;
        root->wordIdx = idx;
    }

    Trie* buildTrie(const vector<string>& words) {
        Trie* root = new Trie();
        for (int i = 0; i < words.size(); ++i)
            insertWord(root, words, i);
        return root;
    }

    int dfs_Trie(vector<string>& res, Trie* root, vector<vector<char>>& board,
        vector<string>& words, int row, int col) {
        int detected = 0;

        if (root->isLeaf) {
            ++detected;
            root->isLeaf = false;
            res.push_back(words[root->wordIdx]);
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()
            || board[row][col] == '*' || !root->children[board[row][col] - 'a']
            || root->children[board[row][col] - 'a']->prefixCount <= 0)
            return detected;
        int curC = board[row][col] - 'a';
        board[row][col] = '*';
        detected += dfs_Trie(res, root->children[curC], board, words, row - 1, col)
            + dfs_Trie(res, root->children[curC], board, words, row + 1, col)
            + dfs_Trie(res, root->children[curC], board, words, row, col - 1)
            + dfs_Trie(res, root->children[curC], board, words, row, col + 1);
        root->prefixCount -= detected;
        board[row][col] = curC + 'a';
        return detected;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int M, N, wordNum = words.size();
        vector<string> res;
        if (!(M = board.size()) || !(N = board[0].size()) || !wordNum)
            return res;
        Trie* root = buildTrie(words);
        for (auto i = 0; i < M && root->prefixCount; ++i)
            for (auto j = 0; j < N; ++j)
                dfs_Trie(res, root, board, words, i, j);
        delete root;
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
