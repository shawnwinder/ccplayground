// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [913] Random Flip Matrix
 *
 * https://leetcode.com/problems/random-flip-matrix/description/
 *
 * algorithms
 * Medium (31.75%)
 * Total Accepted:    1.1K
 * Total Submissions: 3.4K
 * Testcase Example:  '["Solution", "flip", "flip", "flip", "flip"]\n[[2, 2], [], [], [], []]'
 *
 * You are given the number of rows n_rows and number of columns n_cols of a 2D
 * binary matrix where all values are initially 0. Write a function flip which
 * chooses a 0 value uniformly at random, changes it to 1, and then returns the
 * position [row.id, col.id] of that value. Also, write a function reset which
 * sets all values back to 0. Try to minimize the number of calls to system's
 * Math.random() and optimize the time and space complexity.
 *
 * Note:
 *
 *
 * 1 <= n_rows, n_cols <= 10000
 * 0 <= row.id < n_rows and 0 <= col.id < n_cols
 * flip will not be called when the matrix has no 0 values left.
 * the total number of calls to flip and reset will not exceed 1000.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ["Solution","flip","flip","flip","flip"]
 * [[2,3],[],[],[],[]]
 * Output: [null,[0,1],[1,2],[1,0],[1,1]]
 *
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ["Solution","flip","flip","reset","flip"]
 * [[1,2],[],[],[],[]]
 * Output: [null,[0,0],[0,1],null,[0,0]]
 *
 *
 * Explanation of Input Syntax:
 *
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has two arguments, n_rows and n_cols. flip and reset
 * have no arguments. Arguments are always wrapped with a list, even if there
 * aren't any.
 *
 */
class Solution {
    int row = 0;
    int col = 0;
    int cnt = 0;
    unordered_map<int, int> id2pos;

public:
    Solution(int n_rows, int n_cols)
        : row(n_rows)
        , col(n_cols) {
        cnt = row * col;
        srand(time(nullptr));
    }

    vector<int> flip() {
        int id = rand() % cnt;
        vector<int> res;
        if (id2pos.find(id) != id2pos.end()) {
            int pos = id2pos[id];
            res = { pos / col, pos % col };
        } else {
            res = { id / col, id % col };
        }
        if (id2pos.find(cnt - 1) != id2pos.end()) {
            id2pos[id] = id2pos[cnt - 1];
        } else {
            id2pos[id] = cnt - 1;
        }
        --cnt;
        return res;
    }

    void reset() {
        id2pos.clear();
        cnt = row * col;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */

int mymain(int argc, char* argv[]) { return 0; }
