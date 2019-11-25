#include <bits/stdc++.h>
using namespace std;
int w, h, b;
vector<vector<int>> a;
int main() {
    scanf("%d%d%d", &w, &h, &b);
    a.assign(h, vector<int>(w));
    for (int i=0;i<h;++i)
        for (int j=0;j<w;++j) scanf("%d", &a[i][j]);
    while (b--) {
        vector<vector<int>> next(h, vector<int>(w));
        for (int i=0;i<h;++i)
            for (int j=0;j<w;++j)
                for (int dr=-1;dr<=1;++dr)
                    for (int dc=-1;dc<=1;++dc)
                        next[(i+dr+h)%h][(j+dc+w)%w] += a[i][j];
        a = next;
    }
    set<int> s;
    for (int i=0;i<h;++i)
        for (int j=0;j<w;++j) s.insert(a[i][j]);
    printf("%d", s.size());
}