#include <bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> a;
int d[501];
int main() {
    int V = 3, E = 4, u, v, w;
    // u, v, w
    a.push_back({1, 2, 4});
    a.push_back({1, 3, 3});
    a.push_back({2, 3, -1});
    a.push_back({3, 1, -2});


    fill(d, d+501, INT_MAX);
    d[1] = 0;

    bool ncycle = 0;
    for (int i=1;i<=V;++i) {
        for (int j=0;j<E;++j) {
            tie(u,v,w) = a[j];
            if (d[u] != INT_MAX && d[u]+w < d[v]) {
                d[v] = d[u]+w;
                if (i == V) ncycle = true;
            }
        }
    }
    if (ncycle) puts("-1");
    else {
        for (int i=2;i<=V;++i) {
            printf("1 -> %d : ", i);
            if (d[i] == INT_MAX) puts("-1");
            else printf("%d\n", d[i]);
        }
    }
}