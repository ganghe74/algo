#include <bits/stdc++.h>
using namespace std;
int N, M = -1e9, m = 1e9, a[11], cnt[4];
char op[10];

void choice(int idx) {
    if (idx == N-1) {
        int x = a[0];
        for (int i=0;i<N-1;++i) {
            if (op[i] == '*') x *= a[i+1];
            else if (op[i] == '/') x /= a[i+1];
            else if (op[i] == '+') x += a[i+1];
            else x -= a[i+1];
        }
        M = max(M, x);
        m = min(m, x);

        return;
    }
    for (int k=0;k<4;++k) {
        if (cnt[k]) {
            cnt[k]--;
            op[idx] = "+-*/"[k];
            choice(idx+1);
            cnt[k]++;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    for (int i=0;i<4;++i) scanf("%d", &cnt[i]);
    choice(0);
    printf("%d\n%d", M, m);
}