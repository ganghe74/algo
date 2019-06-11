#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, x;
    pair<int,int> pos[2];
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            scanf("%d", &x);
            if (x) {
                pos[1] = pos[0];
                pos[0] = {i, j};
            }
        }
    }
    printf("%d", abs(pos[0].first-pos[1].first) + abs(pos[0].second-pos[1].second));
}