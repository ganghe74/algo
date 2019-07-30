#include <bits/stdc++.h>
using namespace std;

int N, P, status, alive;
int a[16][16], d[1<<17];

int solve(int todo, int status) {
    if (todo <= 0) return 0;
    if (d[status] != -1) return d[status];
    d[status] = INT_MAX;
    for (int i=0;i<N;++i) {
        if (status & (1 << i)) {
            for (int j=0;j<N;++j) {
                if (status & (1 << j)) continue;
                d[status] = min(d[status], solve(todo-1, status | (1 << j)) + a[i][j]);
            }
        }
    }
    return d[status];
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%d ", &a[i][j]);
    }
    for (int i=0;i<N;++i) {
        char c;
        scanf("%c", &c);
        if (c == 'Y') {
            status |= (1 << i);
            alive++;
        }
    }
    scanf("%d", &P);
    if (P > 0 && status == 0) printf("-1");
    else printf("%d", solve(P - alive, status));
}