#include <bits/stdc++.h>
using namespace std;
int L, T, N, pos, a[70000];
char dir;
int main() {
    scanf("%d%d%d", &L, &T, &N);
    for (int i=0;i<N;++i) {
        scanf("%d %c", &pos, &dir);
        if (dir == 'L') pos = 2*L + T - pos;
        else pos = T + pos;
        pos %= 2*L;
        if (pos > L) a[i] = L - pos % L;
        else a[i] = pos;
    }
    sort(a, a+N);
    for (int i=0;i<N;++i) printf("%d ", a[i]);
}