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
    int sum;
};
Value neutral_element = Value({0});

Value combine(Value const &a, Value const &b) {
    return Value({a.sum + b.sum});
}

struct SegmentTree {


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
        if(i < l || i >= r){return;}

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
    cin >> n;
    vector<int>in(n);
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
        if(in[i]<0)in[i]=-in[i];
    }
    int orgSize=3;
    int size = 2*orgSize+1;
    vector<Value> base(size, neutral_element);
    SegmentTree segtree(base);
    SegmentTree segtree2(base);
    vector<int>smallerToRight(n);
    for (int i = n-1; i >= 0; --i) {
        int input=in[i];
        if(input==0){ continue;}
        smallerToRight[i]=segtree2.query(0, input).sum;

        segtree2.update(input, Value({segtree2.query(input, input+1).sum + 1}));
    }

    int numberOfInversions = 0;
    for (int i = 0; i < n; ++i) {
        int input=in[i];
        if(input<0){input=-input;}
        int notInversed=segtree.query(input+orgSize+1, size).sum;
        int inversed = segtree.query(-input+orgSize+1, size).sum;

        if(inversed-smallerToRight[i]<notInversed){
            numberOfInversions+=inversed;
            segtree.update(-input+orgSize, Value({segtree.query(-input+orgSize, -input+orgSize+1).sum + 1}));
        } else{
            numberOfInversions+=notInversed;
            segtree.update(input+orgSize, Value({segtree.query(input+orgSize, input+orgSize+1).sum + 1}));
        }
    }

    cout << numberOfInversions;
}