#include <bits/stdc++.h>
using namespace std;

int H, W, K, ans, a[10][1000], g[10], cnt[10];

void choice(int r, int group) {
    if (r == H) {
        fill(cnt, cnt+10, 0);
        int slice = group;
        for (int j=0;j<W;++j) {
            bool exceed = false;
            for (int i=0;i<H;++i) {
                if (a[i][j]) {
                    if (++cnt[g[i]] > K) exceed = true;
                }
            }
            if (exceed) {
                slice++;
                fill(cnt, cnt+10, 0);
                for (int i=0;i<H;++i) {
                    cnt[g[i]] += a[i][j];
                    if (cnt[g[i]] > K) return;
                }
            }
        }
        ans = min(ans, slice);
        return;
    }
    g[r] = group;
    choice(r+1, group);
    choice(r+1, group+1);
}

int main() {
    scanf("%d%d%d", &H, &W, &K);
    for (int i=0;i<H;++i)
        for (int j=0;j<W;++j) scanf("%1d", &a[i][j]);
    ans = 1e9;
    choice(0, 0);
    printf("%d", ans);
}
