#include <bits/stdc++.h>
#define int long long

using namespace std;

int next_power_of_two(unsigned x) {
    return 1 << (__lg(x - 1) + 1);
}

struct Value1d {
    int left, right, closed;
};

Value1d combine(Value1d const &a, Value1d const &b) {
    int newClosed = min(a.left, b.right)*2;
    return Value1d({a.left + b.left - newClosed/2, a.right + b.right - newClosed/2, a.closed + b.closed + newClosed});
}

struct SegmentTree1d {
    Value1d neutral_element = Value1d({0, 0, 0});

    int n;
    vector<Value1d> tree;

    SegmentTree1d(int min_n)
            : n(next_power_of_two(min_n)),
              tree(2 * n) {}

    SegmentTree1d(vector<Value1d> const &base) : n(next_power_of_two(base.size())),
                                                 tree(2 * n) {
        for (int i = 0; i < (int) base.size(); ++i) {
            tree[n + i] = base[i];
        }
        build(1, 0, n);
    }

    void update(int i, Value1d val) {
        assert(0 <= i && i < n);
        return update_(i, val, 1, 0, n);
    }

    void update_(int i, Value1d val, int pos, int l, int r) {
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

    Value1d query(int l, int r) {
        assert(0 <= l && l < r && r <= n);
        return query_(l, r, 1, 0, n);
    }

    Value1d query_(int ql, int qr, int pos, int l, int r) {
        if (ql <= l && r <= qr) { return tree[pos]; }
        if (qr <= l || r <= ql) { return neutral_element; }

        int m = (l + r) / 2;
        Value1d ans_l = query_(ql, qr, 2 * pos, l, m);
        Value1d ans_r = query_(ql, qr, 2 * pos + 1, m, r);

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

struct Value1d {
    int left, right, closed;
};

Value1d combine(Value1d const &a, Value1d const &b) {
    int newClosed = min(a.left, b.right)*2;
    return Value1d({a.left + b.left - newClosed/2, a.right + b.right - newClosed/2, a.closed + b.closed + newClosed});
}

struct SegmentTree1d {
    Value1d neutral_element = Value1d({0, 0, 0});

    int n;
    vector<Value1d> tree;

    SegmentTree1d(int min_n)
            : n(next_power_of_two(min_n)),
              tree(2 * n) {}

    SegmentTree1d(vector<Value1d> const &base) : n(next_power_of_two(base.size())),
                                                 tree(2 * n) {
        for (int i = 0; i < (int) base.size(); ++i) {
            tree[n + i] = base[i];
        }
        build(1, 0, n);
    }

    void update(int i, Value1d val) {
        assert(0 <= i && i < n);
        return update_(i, val, 1, 0, n);
    }

    void update_(int i, Value1d val, int pos, int l, int r) {
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

    Value1d query(int l, int r) {
        assert(0 <= l && l < r && r <= n);
        return query_(l, r, 1, 0, n);
    }

    Value1d query_(int ql, int qr, int pos, int l, int r) {
        if (ql <= l && r <= qr) { return tree[pos]; }
        if (qr <= l || r <= ql) { return neutral_element; }

        int m = (l + r) / 2;
        Value1d ans_l = query_(ql, qr, 2 * pos, l, m);
        Value1d ans_r = query_(ql, qr, 2 * pos + 1, m, r);

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

    vector<Value1d> base(input.size());
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '(') {
            base[i] = Value1d({1, 0, 0});
        } else {
            base[i] = Value1d({0, 1, 0});
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