#include <iostream>
#include <set>
using namespace std;
int main() {
    int v[101];
    set<int> d[101];
    int N, S, M;
    scanf("%d%d%d", &N, &S, &M);
    d[0].insert(S);
    for (int i=1;i<=N;++i) scanf("%d", &v[i]);
    for (int i=1;i<=N;++i) {
        for (int vol : d[i-1]) {
            if (0 <= vol - v[i] && vol - v[i] <= M) d[i].insert(vol-v[i]);
            if (0 <= vol + v[i] && vol + v[i] <= M) d[i].insert(vol+v[i]);  
        }
    }
    if (d[N].empty()) puts("-1");
    else printf("%d", *d[N].rbegin());
}