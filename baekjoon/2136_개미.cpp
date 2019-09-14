#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, L, pos, l=1e9, r=0, cntl=0;
    vector<pair<int,int>> ant;
    scanf("%d%d", &N, &L);
    for (int i=1;i<=N;++i) {
        scanf("%d", &pos);
        ant.push_back({abs(pos), i});
        if (pos > 0) l = min(l, pos);
        else {
            r = max(r, -pos);
            cntl++;
        }
    }
    sort(ant.begin(), ant.end());
    if (L-l > r) printf("%d %d", ant[cntl].second, L-l);
    else printf("%d %d", ant[cntl-1].second, r);
}