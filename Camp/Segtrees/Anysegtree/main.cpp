#include <bits/stdc++.h>

#define int long long

using namespace std;

int next_power_of_two(unsigned x) {
    return 1 << (__lg(x - 1) + 1);
}

string op = "";
const int mod = 1e9 + 7;

struct Value {
    int x;
};

Value combine(Value const &a, Value const &b) {
    if (op[0] < 'a') {
        if (op == "+") {
            return Value({a.x + b.x});
        } else if (op == "*") {
            return Value({(a.x * b.x) % mod});
        }
    }  else if (op == "gcd") {
        if (a.x == -1 && b.x == -1) {
            return Value({-1});
        } else if (a.x != -1 && b.x != -1) {
            return Value({__gcd(a.x, b.x)});
        } else {
            return Value({max(a.x, b.x)});
        }
    } else if (op[0] == 'm') {
        if (op == "min") {
            return Value({min(a.x, b.x)});
        } else if (op == "max") {
            return Value({max(a.x, b.x)});
        }
    } else if (op == "xor") {
        return Value({a.x ^ b.x});
    }

    return Value{-1};
}

struct SegmentTree {
    Value neutral_element;

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

    int n;
    cin >> op >> n;

    vector<Value> base(n);
    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        base[i] = Value({input});
    }

    int q;
    cin >> q;
    SegmentTree segtree(base);
    if (op == "+") {
        segtree.neutral_element = Value{0};
    } else if (op == "*") {
        segtree.neutral_element = Value{1};
    } else if (op == "min") {
        segtree.neutral_element = Value{(int) 1e10};
    } else if (op == "max") {
        segtree.neutral_element = Value{-1};
    } else if (op == "gcd") {
        segtree.neutral_element = Value{-1};
    } else if (op == "xor") {
        segtree.neutral_element = Value{0};
    }

    for (int i = 0; i < q; ++i) {
        string action;
        cin >> action;

        if (action == "s") {
            int index, newValue;
            cin >> index >> newValue;

            segtree.update(index, Value{newValue});
        } else if (action == "q") {
            int l, r;
            cin >> l >> r;

            cout << segtree.query(l, r).x << "\n";
        }
    }
}
