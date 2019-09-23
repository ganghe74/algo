#include <bits/stdc++.h>
using namespace std;
int T, N, x, y;
vector<pair<int,int>> points;
bool c[20];
long long m;

void choice(int idx, int r) {
    if (r == 0) {
        x = y = 0;
        for (int i=0;i<N;++i) {
            if (c[i]) {
                x += points[i].first;
                y += points[i].second;
            }
            else {
                x -= points[i].first;
                y -= points[i].second;
            }
        }
        m = min(m, 1LL*x*x+1LL*y*y);
        return;
    }
    for (int i=idx;i<N;++i) {
        c[i] = true;
        choice(i+1, r-1);
        c[i] = false;
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        points.clear();
        m = 1e18;
        scanf("%d", &N);
        for (int i=0;i<N;++i) {
            scanf("%d%d", &x, &y);
            points.push_back({x, y});
        }
        choice(0, N/2);
        printf("%lf\n", sqrt(m));
    }
}