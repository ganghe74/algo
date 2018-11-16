#include <bits/stdc++.h>
using namespace std;

int n, d, p, q;
double cache[51][101];
int connected[51][51], deg[51];

double search(int here, int days) { // days일에 here마을에 있을 때, 마지막 날에 q마을에 있을 확률
    if (days == d) return (here == q ? 1 : 0);
    double& ret = cache[here][days];
    if (ret > -0.5) return ret;
    ret = 0;
    for (int there = 0; there<n; ++there)
        if (connected[here][there])
            ret += search(there, days+1) / deg[here];
    return ret;
}

double search2(int here, int days) { // days일에 here마을에 있을확률
    if (days == 0) return (here == p ? 1 : 0);
    double& ret = cache[here][days];
    if (ret > -0.5) return ret;
    ret = 0;
    for (int there=0;there<n;++there)
        if(connected[here][there])
            ret += search2(there, days-1) / deg[there];
    return ret;
}

int main() {
    int C, temp;
    scanf("%d", &C);
    while (C--) {
        memset(deg, 0, sizeof(deg));
        scanf("%d %d %d", &n, &d, &p);
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                scanf("%d", &temp);
                connected[i][j] = temp;
                deg[i] += temp;
            }
        }
        scanf("%d", &temp);
        for (int i=0;i<temp;++i) {
            scanf("%d", &q);
            for (int i=0;i<=50;++i) {
                for (int j=0;j<=100;++j) cache[i][j] = -1;
            }
            // printf("%0.8f ", search(p, 0));
            printf("%0.8f ", search2(q, d));
        }
        printf("\n");
    }
}