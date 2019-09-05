#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+9;
int d[101][101], path[101][101];
stack<int> st;

void find_path(int i, int j) {
    if (!path[i][j]) {
        st.push(j);
        return;
    }
    find_path(path[i][j], j);
    find_path(i, path[i][j]);
}

int main() {
    for (int i=1;i<=100;++i) {
        for (int j=1;j<=100;++j) {
            if (i == j) continue;
            d[i][j] = INF;
        }
    }
    int N, M;
    scanf("%d%d", &N, &M);
    while (M--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }
    for (int k=1;k<=N;++k) {
        for (int i=1;i<=N;++i) {
            for (int j=1;j<=N;++j) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            if (d[i][j] == INF) printf("0 ");
            else printf("%d ", d[i][j]);
        }
        puts("");
    }
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            if (i == j || d[i][j] == INF) puts("0");
            else {
                find_path(i, j);
                st.push(i);
                printf("%d ", st.size());
                while (!st.empty()) {
                    printf("%d ", st.top());
                    st.pop();
                }
                puts("");
            }
        }
    }
}