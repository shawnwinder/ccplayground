// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (28.81%)
 * Total Accepted:    201.1K
 * Total Submissions: 697.9K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 *
 * Example:
 *
 *
 * board =
 * [
 *  ['A','B','C','E'],
 *  ['S','F','C','S'],
 *  ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 *
 *
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; x < board[y].size(); x++) {
                if (exist(board, y, x, word, 0))
                    return true;
            }
        }
        return false;
    }

private:
    bool exist(vector<vector<char>>& board, int y, int x, string& word, int i) {
        if (i == word.size())
            return true;
        if (y < 0 || x < 0 || y == board.size() || x == board[y].size())
            return false;
        if (board[y][x] != word[i])
            return false;
        board[y][x] ^= 128;
        bool flag = exist(board, y, x + 1, word, i + 1) || exist(board, y, x - 1, word, i + 1)
            || exist(board, y + 1, x, word, i + 1) || exist(board, y - 1, x, word, i + 1);
        board[y][x] ^= 128;
        return flag;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
