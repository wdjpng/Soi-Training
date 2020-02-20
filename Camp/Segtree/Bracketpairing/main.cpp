#include <iostream>
#include <vector>
#include <deque>
#include <assert.h>
#include <fstream>

#define int long long

using namespace std;

int next_power_of_two(unsigned x) {
    return 1 << (__lg(x - 1) + 1);
}

struct Value {
    int left, right, closed;
};

Value combine(Value const &a, Value const &b) {
    int newClosed = min(a.left, b.right)*2;
    return Value({a.left + b.left - newClosed/2, a.right + b.right - newClosed/2, a.closed + b.closed + newClosed});
}

struct SegmentTree {
    Value neutral_element = Value({0, 0, 0});

    int n;
    vector<Value> tree;

    SegmentTree(int min_n)
            : n(next_power_of_two(min_n)),
              tree(2 * n) {}

    SegmentTree(vector<Value> const &base) : n(next_power_of_two(base.size())),
                                             tree(2 * n) {
        for (int i = 0; i < (int) base.size(); ++i) {
            tree[n + i] = base[i];
        }
        build(1, 0, n);
    }

    void update(int i, Value val) {
        assert(0 <= i && i < n);
        return update_(i, val, 1, 0, n);
    }

    void update_(int i, Value val, int pos, int l, int r) {
        if (l == i && i + 1 == r) {
            tree[pos] = val;
            return;
        }
        if (i < l || i >= r) { return; }

        int m = (l + r) / 2;
        update_(i, val, 2 * pos, l, m);
        update_(i, val, 2 * pos + 1, m, r);

        tree[pos] = combine(tree[2 * pos], tree[2 * pos + 1]);
    }

    Value query(int l, int r) {
        assert(0 <= l && l < r && r <= n);
        return query_(l, r, 1, 0, n);
    }

    Value query_(int ql, int qr, int pos, int l, int r) {
        if (ql <= l && r <= qr) { return tree[pos]; }
        if (qr <= l || r <= ql) { return neutral_element; }

        int m = (l + r) / 2;
        Value ans_l = query_(ql, qr, 2 * pos, l, m);
        Value ans_r = query_(ql, qr, 2 * pos + 1, m, r);

        return combine(ans_l, ans_r);
    }

    void build(int pos, int l, int r) {
        if (r - l == 1)return;;
        int m = (l + r) / 2;
        build(2 * pos, l, m);
        build(2 * pos + 1, m, r);
        tree[pos] = combine(tree[2 * pos], tree[2 * pos + 1]);
    }
};


signed main() {
    // Turn off synchronization between cin/cout and scanf/printf
    ios_base::sync_with_stdio(false);
    // Disable automatic flush of cout when reading from cin cin.tie(0);
    cin.tie(0);

    int q;
    string input;
    cin >> input >> q;

    vector<Value> base(input.size());
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '(') {
            base[i] = Value({1, 0, 0});
        } else {
            base[i] = Value({0, 1, 0});
        }
    }

    SegmentTree segtree(base);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        if(l==r){
            cout << 0<<"\n";
        } else{
            cout << segtree.query(l-1, r).closed << "\n";
        }
    }

}