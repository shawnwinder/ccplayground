// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <ccutils/microbench.hpp>

using namespace std;

class SegmentTree {
    int n;
    int num;
    struct Node {
        int min;
        int max;
        int l;
        int r;
        int lazy{ 0 };
        bool invalid{ true };
    };
    vector<Node> nodes;

    int queryImpl(int i, int k) {
        if (nodes[i].invalid) {
            int p1 = queryImpl(i * 2, k);
            int p2 = queryImpl(i * 2 + 1, k);
            return p1 + p2;
        }
        if (nodes[i].lazy != 0) {
            nodes[i].min += nodes[i].lazy;
            nodes[i].max += nodes[i].lazy;
            if (nodes[i].l != nodes[i].r) {
                nodes[i * 2].lazy += nodes[i].lazy;
                nodes[i * 2 + 1].lazy += nodes[i].lazy;
            }
            nodes[i].lazy = 0;
        }
        if (nodes[i].min > k) {
            return 0;
        }
        if (nodes[i].max <= k) {
            return nodes[i].r - nodes[i].l + 1;
        }
        int p1 = queryImpl(i * 2, k);
        int p2 = queryImpl(i * 2 + 1, k);
        return p1 + p2;
    };

    void removeImpl(int i, int l, int r) {
        if (nodes[i].invalid) {
            removeImpl(i * 2, l, r);
            removeImpl(i * 2 + 1, l, r);
            return;
        }
        if (nodes[i].lazy != 0) {
            nodes[i].min += nodes[i].lazy;
            nodes[i].max += nodes[i].lazy;
            if (nodes[i].l != nodes[i].r) {
                nodes[i * 2].lazy += nodes[i].lazy;
                nodes[i * 2 + 1].lazy += nodes[i].lazy;
            }
            nodes[i].lazy = 0;
        }
        if (nodes[i].l > nodes[i].r or nodes[i].l > r or nodes[i].r < l)
            return;
        if (nodes[i].l >= l and nodes[i].r <= r) {
            nodes[i].min--;
            nodes[i].max--;
            if (nodes[i].l != nodes[i].r) {
                nodes[i * 2].lazy--;
                nodes[i * 2 + 1].lazy--;
            }
            return;
        }
        removeImpl(i * 2, l, r);
        removeImpl(i * 2 + 1, l, r);
        nodes[i].min = nodes[i * 2].min;
        nodes[i].max = nodes[i * 2 + 1].max;
    };

public:
    SegmentTree(int n_)
        : n(n_)
        , num(n)
        , nodes(2 * n) {
        for (auto i = n; i < 2 * n; ++i) {
            nodes[i] = { i - n + 1, i - n + 1, i - n + 1, i - n + 1 };
            nodes[i].invalid = false;
        }
        for (auto i = n; --i > 0;) {
            if (nodes[i * 2].invalid || nodes[i * 2 + 1].invalid
                || nodes[i * 2].r >= nodes[i * 2 + 1].l)
                continue;
            nodes[i].invalid = false;
            nodes[i].l = nodes[i * 2].l;
            nodes[i].min = nodes[i * 2].min;
            nodes[i].r = nodes[i * 2 + 1].r;
            nodes[i].max = nodes[i * 2 + 1].max;
        }
    }
    int query(int k) {
        if (k > num)
            return -1;
        return queryImpl(1, k);
    }

    void remove(int k) {
        auto nk = query(k);
        if (nk <= 0)
            return;
        num --;
        removeImpl(1, query(k) + 1, n);
    };

    int size() { return num; }
};

int mymain(int argc, char* argv[]) {
    SegmentTree t(1<<20);
    std::cout << ccutils::microbench<std::chrono::milliseconds, 1, 1>([&]() {
        for (auto i = 1u; i <= 1<<20; ++i) {
            t.remove(i);
            t.query(i);
        }
    }) << endl;
    return 0;
}
