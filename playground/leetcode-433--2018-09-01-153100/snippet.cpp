// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * [433] Minimum Genetic Mutation
 *
 * https://leetcode.com/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (35.77%)
 * Total Accepted:    15.4K
 * Total Submissions: 43K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * A gene string can be represented by an 8-character long string, with choices
 * from "A", "C", "G", "T".
 *
 * Suppose we need to investigate about a mutation (mutation from "start" to
 * "end"), where ONE mutation is defined as ONE single character changed in the
 * gene string.
 *
 * For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
 *
 * Also, there is a given gene "bank", which records all the valid gene
 * mutations. A gene must be in the bank to make it a valid gene string.
 *
 * Now, given 3 things - start, end, bank, your task is to determine what is
 * the minimum number of mutations needed to mutate from "start" to "end". If
 * there is no such a mutation, return -1.
 *
 * Note:
 *
 *
 * Starting point is assumed to be valid, so it might not be included in the
 * bank.
 * If multiple mutations are needed, all mutations during in the sequence must
 * be valid.
 * You may assume start and end string is not the same.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * start: "AACCGGTT"
 * end:   "AACCGGTA"
 * bank: ["AACCGGTA"]
 *
 * return: 1
 *
 *
 *
 *
 * Example 2:
 *
 *
 * start: "AACCGGTT"
 * end:   "AAACGGTA"
 * bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
 *
 * return: 2
 *
 *
 *
 *
 * Example 3:
 *
 *
 * start: "AAAAACCC"
 * end:   "AACCCCCC"
 * bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
 *
 * return: 3
 *
 *
 *
 *
 */
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(end))
            return -1;
        unordered_set<string> bset, eset;
        bset.insert(start), eset.insert(end);
        int step = 0, n = start.size();
        while (!bset.empty() and !eset.empty()) {
            if (bset.size() <= eset.size())
                swap(bset, eset);
            unordered_set<string> tmp;
            step++;
            for (auto itr = bset.begin(); itr != bset.end(); ++itr) {
                for (int i = 0; i < n; ++i) {
                    string dna = *itr;
                    for (auto g : string("ATGC")) {
                        dna[i] = g;
                        if (eset.count(dna))
                            return step;
                        if (dict.count(dna)) {
                            tmp.insert(dna);
                            dict.erase(dna);
                        }
                    }
                }
            }
            bset = std::move(tmp);
        }
        return -1;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
