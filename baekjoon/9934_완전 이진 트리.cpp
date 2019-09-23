#include <bits/stdc++.h>
using namespace std;
int K, x;
vector<int> a, tree[10];

void solve(int l, int r, int level) {
    tree[level].push_back(a[(l+r)/2]);
    if (l == r) return;
    solve(l, (l+r)/2-1, level+1);
    solve((l+r)/2+1, r, level+1);
}

int main() {
    scanf("%d", &K);
    for (int i=pow(2,K);i>1;--i) {
        scanf("%d", &x);
        a.push_back(x);
    }
    solve(0, pow(2,K)-2, 0);
    for (int i=0;i<K;++i) {
        for (int x : tree[i]) printf("%d ", x);
        puts("");
    }
}