#include <iostream>
using namespace std;
bool a[200][200];
bool c[200];
void dfs(int now) {
    c[now] = true;
    for (int i=0;i<200;++i) {
        if (a[now][i] && !c[i]) dfs(i);
    }
}
int main() {
    int N, M;
    int t[1000];
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
    }
    for (int i=0;i<M;++i) scanf("%d", &t[i]);
    dfs(t[0]-1);
    bool ok = true;
    for (int i=0;i<M;++i) {
        if (c[t[i]-1] == 0) ok = false;
    }
    if (ok) printf("YES");
    else printf("NO");
}