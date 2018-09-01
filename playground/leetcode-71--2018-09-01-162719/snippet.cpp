// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (26.91%)
 * Total Accepted:    123K
 * Total Submissions: 457K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * Corner Cases:
 *
 *
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 *
 *
 */
class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, tmp, '/')) {
            if (tmp == "" or tmp == ".")
                continue;
            if (tmp == ".." and !stk.empty())
                stk.pop_back();
            else if (tmp != "..")
                stk.push_back(tmp);
        }
        for (auto str : stk)
            res += "/" + str;
        return res.empty() ? "/" : res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
