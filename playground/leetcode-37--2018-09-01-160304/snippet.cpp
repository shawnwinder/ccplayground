// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (33.28%)
 * Total Accepted:    100.8K
 * Total Submissions: 302.9K
 * Testcase Example:
 * [
 *  ["5","3",".",".","7",".",".",".","."],
 *  ["6",".",".","1","9","5",".",".","."],
 *  [".","9","8",".",".",".",".","6","."],
 *  ["8",".",".",".","6",".",".",".","3"],
 *  ["4",".",".","8",".","3",".",".","1"],
 *  ["7",".",".",".","2",".",".",".","6"],
 *  [".","6",".",".",".",".","2","8","."],
 *  [".",".",".","4","1","9",".",".","5"],
 *  [".",".",".",".","8",".",".","7","9"]
 * ]
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * Empty cells are indicated by the character '.'.
 *
 *
 * A sudoku puzzle...
 *
 *
 * ...and its solution numbers marked in red.
 *
 * Note:
 *
 *
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 *
 *
 */

// This is one of the fastest Sudoku solvers I've ever written. It is compact enough - just 150
// lines of C++ code with comments. I thought it'd be interesting to share it, since it combines
// several techniques like reactive network update propagation and backtracking with very aggressive
// pruning.

// The algorithm is online - it starts with an empty board and as you add numbers to it, it starts
// solving the Sudoku.

// Unlike in other solutions where you have bitmasks of allowed/disallowed values per
// row/column/square, this solution track bitmask for every(!) cell, forming a set of constraints
// for the allowed values for each particular cell. Once a value is written into a cell, new
// constraints are immediately propagated to row, column and 3x3 square of the cell. If during this
// process a value of other cell can be unambiguously deduced - then the value is set, new
// constraints are propagated, so on.... You can think about this as an implicit reactive network of
// cells.

// If we're lucky (and we'll be lucky for 19 of 20 of Sudokus published in magazines) then Sudoku is
// solved at the end (or even before!) processing of the input.

// Otherwise, there will be empty cells which have to be resolved. Algorithm uses backtracking for
// this purpose. To optimize it, algorithm starts with the cell with the smallest ambiguity. This
// could be improved even further by using priority queue (but it's not implemented here).
// Backtracking is more or less standard, however, at each step we guess the number, the reactive
// update propagation comes back into play and it either quickly proves that the guess is unfeasible
// or significantly prunes the remaining search space.

// It's interesting to note, that in this case taking and restoring snapshots of the compact
// representation of the state is faster than doing backtracking rollback by "undoing the moves".
class Solution {
    struct cell // encapsulates a single cell on a Sudoku board
    {
        uint8_t value; // cell value 1..9 or 0 if unset
        // number of possible (unconstrained) values for the cell
        uint8_t numPossibilities;
        // if bitset[v] is 1 then value can't be v
        bitset<10> constraints;
        cell()
            : value(0)
            , numPossibilities(9)
            , constraints(){};
    };
    array<array<cell, 9>, 9> cells;

    // sets the value of the cell to [v]
    // the function also propagates constraints to other cells and deduce new values where possible
    bool set(int i, int j, int v) {
        // updating state of the cell
        cell& c = cells[i][j];
        if (c.value == v)
            return true;
        if (c.constraints[v])
            return false;
        c.constraints = bitset<10>(0x3FE); // all 1s
        c.constraints.reset(v);
        c.numPossibilities = 1;
        c.value = v;

        // propagating constraints
        for (int k = 0; k < 9; k++) {
            // to the row:
            if (i != k && !updateConstraints(k, j, v))
                return false;
            // to the column:
            if (j != k && !updateConstraints(i, k, v))
                return false;
            // to the 3x3 square:
            int ix = (i / 3) * 3 + k / 3;
            int jx = (j / 3) * 3 + k % 3;
            if (ix != i && jx != j && !updateConstraints(ix, jx, v))
                return false;
        }
        return true;
    }
    // update constraints of the cell i,j by excluding possibility of 'excludedValue'
    // once there's one possibility left the function recurses back into set()
    bool updateConstraints(int i, int j, int excludedValue) {
        cell& c = cells[i][j];
        if (c.constraints[excludedValue]) {
            return true;
        }
        if (c.value == excludedValue) {
            return false;
        }
        c.constraints.set(excludedValue);
        if (--c.numPossibilities > 1)
            return true;
        for (int v = 1; v <= 9; v++) {
            if (!c.constraints[v]) {
                return set(i, j, v);
            }
        }
    }

    // backtracking state - list of empty cells
    vector<pair<int, int>> bt;

    // find values for empty cells
    bool findValuesForEmptyCells() {
        // collecting all empty cells
        bt.clear();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!cells[i][j].value)
                    bt.push_back(make_pair(i, j));
            }
        }
        // making backtracking efficient by pre-sorting empty cells by numPossibilities
        sort(bt.begin(), bt.end(), [this](const pair<int, int>& a, const pair<int, int>& b) {
            return cells[a.first][a.second].numPossibilities
                < cells[b.first][b.second].numPossibilities;
        });
        return backtrack(0);
    }

    // Finds value for all empty cells with index >=k
    bool backtrack(int k) {
        if (k >= bt.size())
            return true;
        int i = bt[k].first;
        int j = bt[k].second;
        // fast path - only 1 possibility
        if (cells[i][j].value)
            return backtrack(k + 1);
        auto constraints = cells[i][j].constraints;
        // slow path >1 possibility.
        // making snapshot of the state
        array<array<cell, 9>, 9> snapshot(cells);
        for (int v = 1; v <= 9; v++) {
            if (!constraints[v]) {
                if (set(i, j, v)) {
                    if (backtrack(k + 1))
                        return true;
                }
                // restoring from snapshot,
                // note: computationally this is cheaper
                // than alternative implementation with undoing the changes
                cells = snapshot;
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        cells = array<array<cell, 9>, 9>(); // clear array
        // Decoding input board into the internal cell matrix.
        // As we do it - constraints are propagated and even additional values are set as we go
        // (in the case if it is possible to unambiguously deduce them).
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !set(i, j, board[i][j] - '0'))
                    return; // sudoku is either incorrect or unsolvable
            }
        }
        // if we're lucky we've already got a solution,
        // however, if we have empty cells we need to use backtracking to fill them
        if (!findValuesForEmptyCells())
            return; // sudoku is unsolvable

        // copying the solution back to the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (cells[i][j].value)
                    board[i][j] = cells[i][j].value + '0';
            }
        }
    }
};

int mymain(int argc, char* argv[]) { return 0; }
