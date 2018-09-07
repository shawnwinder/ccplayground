// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (34.50%)
 * Total Accepted:    76.1K
 * Total Submissions: 220.7K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 *
 *
 *
 * Example:
 *
 *
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 *
 * Note:
 *
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 *
 */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A > C)
            swap(A, C);
        if (B > D)
            swap(B, D);
        if (E > G)
            swap(E, G);
        if (F > H)
            swap(F, H);
        long x = max(A, E), y = max(B, F), xx = min(C, G), yy = min(D, H);
        return (long)(C - A) * (D - B) + (long)(G - E) * (H - F)
            - max(xx - x, 0l) * max(yy - y, 0l);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
