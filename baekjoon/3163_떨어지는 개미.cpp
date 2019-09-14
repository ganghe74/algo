#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N, L, K, pos, id;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &N, &L, &K);
        vector<pair<int,int>> ant;
        vector<int> a, l, r;
        for (int i=0;i<N;++i) {
            scanf("%d%d", &pos, &id);
            a.push_back(id);
            if (id > 0) r.push_back(L - pos);
            else l.push_back(pos);
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        for (int i=0;i<l.size();++i) ant.push_back({l[i], a[i]});
        for (int i=0;i<r.size();++i) ant.push_back({r[i], a[N-i-1]});
        sort(ant.begin(), ant.end());
        printf("%d\n", ant[K-1].second);
    }
}