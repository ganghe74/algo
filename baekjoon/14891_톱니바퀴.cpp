#include <bits/stdc++.h>
using namespace std;

int k, n, dir, gear[4];

int main() {
    for (int i=0;i<4;++i) {
        int state = 0, t;
        for (int j=0;j<8;++j) {
            scanf("%1d", &t);
            if (t) state |= (1 << j);
        }
        gear[i] = state;
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &n, &dir);
        vector<int> dirs(4);
        dirs[--n] = dir;
        for (int i=1;n+i<4;++i) {
            if (!dirs[n+i-1]) break;
            bool l3 = gear[n+i-1] & (1 << 2);
            bool r9 = gear[n+i] & (1 << 6);
            if (l3 != r9) dirs[n+i] = -dirs[n+i-1];
        }
        for (int i=1;n-i>=0;++i) {
            if (!dirs[n-i+1]) break;
            bool r9 = gear[n-i+1] & (1 << 6);
            bool l3 = gear[n-i] & (1 << 2);
            if (l3 != r9) dirs[n-i] = -dirs[n-i+1];
        }
        for (int i=0;i<4;++i) {
            if (dirs[i] == -1) gear[i] = (gear[i] << 7) | (gear[i] >> 1);
            else if (dirs[i] == 1) gear[i] = (gear[i] << 1) | (gear[i] >> 7);
            gear[i] &= (1<<8)-1;
        }
    }
    int ans = 0;
    for (int i=0;i<4;++i)
        if (gear[i] & 1)
            ans += (1 << i);
    printf("%d", ans);
}
