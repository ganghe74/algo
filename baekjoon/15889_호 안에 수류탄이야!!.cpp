#include <bits/stdc++.h>
using namespace std;

int N, pos[30000], range[30000];
bool c[30000];

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &pos[i]);
    for (int i=0;i<N-1;++i) scanf("%d", &range[i]);

    c[0] = 1;
    for (int i=0;i<N;++i) {
        if (!c[i]) break;
        int lo = lower_bound(pos, pos+N, pos[i] - range[i]) - pos;
        int hi = upper_bound(pos, pos+N, pos[i] + range[i]) - pos;
        while (lo < hi) c[lo++] = 1;

    }

    puts(c[N-1] ? "권병장님, 중대장님이 찾으십니다" : "엄마 나 전역 늦어질 것 같아");
}
