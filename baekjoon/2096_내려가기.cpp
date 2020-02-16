#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a[3], dmin[2][3], dmax[2][3];
    scanf("%d", &N);
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    for (int i=0;i<3;++i) dmin[0][i] = dmax[0][i] = a[i];
    while (--N) {
        scanf("%d%d%d", &a[0], &a[1], &a[2]);
        dmin[1][0] = a[0] + min(dmin[0][0], dmin[0][1]);
        dmin[1][1] = a[1] + min({dmin[0][0], dmin[0][1], dmin[0][2]});
        dmin[1][2] = a[2] + min(dmin[0][1], dmin[0][2]);
        dmax[1][0] = a[0] + max(dmax[0][0], dmax[0][1]);
        dmax[1][1] = a[1] + max({dmax[0][0], dmax[0][1], dmax[0][2]});
        dmax[1][2] = a[2] + max(dmax[0][1], dmax[0][2]);
        for (int i=0;i<3;++i) {
            dmin[0][i] = dmin[1][i];
            dmax[0][i] = dmax[1][i];
        }
    }
    printf("%d %d", max({dmax[0][0], dmax[0][1], dmax[0][2]}), min({dmin[0][0], dmin[0][1], dmin[0][2]}));
}
