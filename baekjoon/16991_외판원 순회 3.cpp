#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int N, x, y;
Point p[16];
double a[16][16], d[16][1<<16];

double solve(int now, int status) {
    double &ret = d[now][status];
    if (ret) return ret;
    if (status == (1 << N)-1 && a[now][0]) return ret = a[now][0];
    ret = 1e9;
    for (int i=0;i<N;++i) {
        if (!(status & (1 << i)) && a[now][i])
            ret = min(ret, solve(i, status | (1 << i)) + a[now][i]);
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
        for (int j=0;j<i;++j) {
            a[i][j] = a[j][i] = sqrt(pow(p[i].x-p[j].x, 2) + pow(p[i].y-p[j].y, 2));
        }
    }

    printf("%lf", solve(0, 1));
}