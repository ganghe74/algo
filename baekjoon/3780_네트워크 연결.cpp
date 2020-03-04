#include <bits/stdc++.h>
using namespace std;

int T, N, I, J, p[20001], l[20001];
char op;

int Find(int u) {
    if (u == p[u]) return u;
    int x = Find(p[u]);
    l[u] += l[p[u]];
    return p[u] = x;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i=1;i<=N;++i) p[i] = i, l[i] = 0;
        while (true) {
            scanf(" %c", &op);
            if (op == 'O') break;
            if (op == 'E') {
                scanf("%d", &I);
                Find(I);
                printf("%d\n", l[I]);
            }
            else {
                scanf("%d%d", &I, &J);
                p[I] = J;
                l[I] = abs(I-J) % 1000;
            }
        }
    }
}
