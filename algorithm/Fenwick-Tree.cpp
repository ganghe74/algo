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

int main() {
    FenwickTree t(10);
    for (int i=0;i<10;++i) t.add(i, i);
    for (int i=0;i<10;++i) printf("%d\n", t.sum(i));
}
