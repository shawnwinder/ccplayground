// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (33.88%)
 * Total Accepted:    103.2K
 * Total Submissions: 304.5K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 *
 * Example:
 *
 *
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 *
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 *
 *
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string a) {
        unsigned i = 0, n = a.size(), t = 0;
        unordered_map<unsigned, unsigned> m;
        vector<string> r;
        while (i < min(9u, n))
            t = t << 3 | (a[i++] & 7);
        while (i < n)
            if (m[t = (t << 3 & 0x3fffffff) | (a[i++] & 7)]++ == 1)
                r.push_back(a.substr(i - 10, 10));
        return r;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
