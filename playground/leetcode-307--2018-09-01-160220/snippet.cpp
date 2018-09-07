// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (24.20%)
 * Total Accepted:    51.1K
 * Total Submissions: 211K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i <= j), inclusive.
 *
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 *
 * Example:
 *
 *
 * Given nums = [1, 3, 5]
 *
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 *
 *
 * Note:
 *
 *
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 *
 *
 */
class NumArray {
    int n;
    struct Node {
        int sum;
        int l;
        int r;
        bool valid{ false };
    };
    vector<Node> nodes;

    void updateImpl(int x, int i, int val) {
        if (x >= n) return;
        if (nodes[x].valid) {
            if (nodes[x].l > i || nodes[x].r < i)
                return;
            nodes[x].sum += val;
        }
        updateImpl(x * 2, i, val);
        updateImpl(x * 2 + 1, i, val);
    }

    int sumRangeImpl(int x, int i, int j) {
        if (x >= n) return 0;
        if (nodes[x].valid) {
            if (nodes[x].l > j || nodes[x].r < i)
                return 0;
            if (nodes[x].l >= i && nodes[x].r <= j)
                return nodes[x].sum;
        }
        return sumRangeImpl(x * 2, i, j) + sumRangeImpl(x * 2 + 1, i, j);
    }

public:
    NumArray(vector<int> nums) {
        n = nums.size() * 2;
        nodes.resize(n);
        for (auto i = n / 2; i < n; ++i) {
            nodes[i].sum = nums[i - n / 2];
            nodes[i].l = nodes[i].r = i - n / 2;
            nodes[i].valid = true;
        }
        for (auto i = n / 2; --i > 0;) {
            if (!nodes[i * 2].valid || !nodes[i * 2 + 1].valid
                || nodes[i * 2].r >= nodes[i * 2 + 1].l)
                continue;
            nodes[i].valid = true;
            nodes[i].l = nodes[i * 2].l;
            nodes[i].r = nodes[i * 2 + 1].r;
            nodes[i].sum = nodes[i * 2].sum + nodes[i * 2 + 1].sum;
        }
    }

    void update(int i, int val) { updateImpl(1, i, val - nodes[i + n / 2].sum); }

    int sumRange(int i, int j) { return sumRangeImpl(1, i, j); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int mymain(int argc, char* argv[]) {
    vector<int> nums = {1,2,3};
    NumArray obj(nums);
    obj.update(2, 1);
    cout << obj.sumRange(0, 2);
    return 0;
}
