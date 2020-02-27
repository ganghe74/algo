#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    int n;
    vector<int> tree;
    FenwickTree(int n) : tree(n+1) {}
    int sum(int pos) {
        ++pos;
        int ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos-1);
        }
        return ret;
    }
    void add(int pos, int val) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

long long countMoves(const vector<int>& A) {
    FenwickTree tree(1000000);
    long long ret = 0;
    for (int i=0;i<A.size();++i) {
        ret += tree.sum(999999) - tree.sum(A[i]);
        tree.add(A[i], 1);
    }
    return ret;
}

int main() {
    int C, N, x;
    scanf("%d", &C);
    while (C--) {
        scanf("%d", &N);
        vector<int> a(N);
        for (int i=0;i<N;++i) scanf("%d", &a[i]);
        printf("%lld\n", countMoves(a));
    }
}
