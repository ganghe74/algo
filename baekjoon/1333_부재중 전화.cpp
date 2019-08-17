#include <bits/stdc++.h>
using namespace std;
bool c[1001000];
int main() {
    int N, L, D;
    scanf("%d%d%d", &N, &L, &D);
    int t=0;
    while (N--) {
        for (int i=0;i<L;++i) c[t++] = 1;
        t += 5;
    }
    t = 0;
    while (c[t]) t+=D;
    printf("%d", t);
}