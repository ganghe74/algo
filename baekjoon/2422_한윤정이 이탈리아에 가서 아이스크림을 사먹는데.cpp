#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
bool no[201][201];
int a[3];

void choice(int idx, int cnt) {
    if (cnt == 3) {
        if (!no[a[0]][a[1]] && !no[a[0]][a[2]] && !no[a[1]][a[2]]) ans++;
        return;
    }
    for (int i=idx;i<=N;++i) {
        a[cnt] = i;
        choice(i+1, cnt+1);
    }
}

int main() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        no[a][b] = 1;
        no[b][a] = 1;
    }
    choice(1, 0);
    printf("%d", ans);
}