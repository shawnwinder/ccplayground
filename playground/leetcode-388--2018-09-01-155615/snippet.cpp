// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [388] Longest Absolute File Path
 *
 * https://leetcode.com/problems/longest-absolute-file-path/description/
 *
 * algorithms
 * Medium (37.82%)
 * Total Accepted:    52.9K
 * Total Submissions: 140K
 * Testcase Example:  '"dir\\n\\tsubdir1\\n\\tsubdir2\\n\\t\\tfile.ext"'
 *
 * Suppose we abstract our file system by a string in the following manner:
 *
 * The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 *
 * dir
 * ⁠   subdir1
 * ⁠   subdir2
 * ⁠       file.ext
 *
 *
 * The directory dir contains an empty sub-directory subdir1 and a
 * sub-directory subdir2 containing a file file.ext.
 *
 * The string
 * "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
 * represents:
 *
 * dir
 * ⁠   subdir1
 * ⁠       file1.ext
 * ⁠       subsubdir1
 * ⁠   subdir2
 * ⁠       subsubdir2
 * ⁠           file2.ext
 *
 *
 * The directory dir contains two sub-directories subdir1 and subdir2. subdir1
 * contains a file file1.ext and an empty second-level sub-directory
 * subsubdir1. subdir2 contains a second-level sub-directory subsubdir2
 * containing a file file2.ext.
 *
 * We are interested in finding the longest (number of characters) absolute
 * path to a file within our file system. For example, in the second example
 * above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and
 * its length is 32 (not including the double quotes).
 *
 * Given a string representing the file system in the above format, return the
 * length of the longest absolute path to file in the abstracted file system.
 * If there is no file in the system, return 0.
 *
 * Note:
 *
 * The name of a file contains at least a . and an extension.
 * The name of a directory or sub-directory will not contain a ..
 *
 *
 *
 * Time complexity required: O(n) where n is the size of the input string.
 *
 * Notice that a/aa/aaa/file1.txt is not the longest file path, if there is
 * another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
 */
class Solution {
public:
    int lengthLongestPath(string input) {
        int ret = 0;
        int cur = 0;
        int level = 0;
        vector<int> parent (1024, 0);
        bool dot = false;
        bool escape = false;
        input += "\n";
        int space = 0;
        int state = 0;
        int w = 0;
        for (auto c : input) {
            if (c == '\n') {
                    if (dot) {
                        int sum = 0;
                        for (int i=0;i<level;i++) {
                            sum += parent[i];
                        }
                        sum += cur - w;
                        if (sum > ret) ret = sum;
                    } else {
                        parent[level] = cur + 1 - w;
                    }
                    level = 0;
                                    dot = false;
                                    space = 0;
                                    cur = 0;
                                    state = 0;
                                    w = 0;
            } else if (c == '\t') {
                    level ++;
                    dot = false;
                                    cur = 0;
                                    space = 0;
                                    state = 0;
                                    w = 0;
            w = 0;
            } else {
                if (c == '.') {
                    dot = true;
                }
                

                    cur ++;

            }
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
