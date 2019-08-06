#include <bits/stdc++.h>
using namespace std;

int N;
int a[100][100], c[100];

void dfs(int now) {
    for (int i=0;i<N;++i) {
        if (a[now][i] && !c[i]) {
            c[i] = 1;
            dfs(i);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j) scanf("%d", &a[i][j]);

    for (int i=0;i<N;++i) {
        memset(c, 0, sizeof(c));
        dfs(i);
        for (int j=0;j<N;++j) printf("%d ", c[j]);
        puts("");
    }
}