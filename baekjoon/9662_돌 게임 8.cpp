#include <bits/stdc++.h>
using namespace std;

int m, k;
map<int,int> last;
vector<int> r, moves;

int main() {
    scanf("%d%d", &m, &k);
    moves.resize(k);
    for (int i=0;i<k;++i)
        scanf("%d", &moves[i]);
    int mask = (1 << 22) - 1;
    int ans = -1;
    for (int i=0;i<=m;++i) {
        mask <<= 1;
        ans += 1;
        for (int j : moves) {
            if ((mask & (1 << j)) == 0) {
                mask += 1;
                ans -= 1;
                break;
            }
        }
        mask &= (1 << 22) - 1;
        if (last.count(mask)) {
            int pLength = i - last[mask];
            int cnt = (m - i) / pLength;
            ans += cnt * (ans - r[last[mask]]);
            i += cnt * pLength;
        }
        r.push_back(ans);
        last[mask] = i;
    }
    printf("%d", ans);
}
