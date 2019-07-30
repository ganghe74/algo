#include <bits/stdc++.h>
using namespace std;

int N, F;
int a[11], d[11][11];
bool c[11];

int f() {
    int ret = 0;
    for (int i=0;i<N;++i) {
        ret += d[N][i] * a[i];
    }
    return ret;
}

bool choice(int idx) {
    if (idx == N) {
        if (f() == F) return true;
        return false;
    }
    for (int i=1;i<=N;++i) {
        if (!c[i]) {
            a[idx] = i;
            c[i] = 1;
            if (choice(idx+1)) return true;;
            c[i] = 0;
        }
    }
    return false;
}

int main() {
    d[1][0] = 1;
    for (int i=1;i<10;++i) {
        for (int j=0;j<10;++j) {
            d[i+1][j] += d[i][j];
            d[i+1][j+1] += d[i][j];
        }
    }
    scanf("%d%d", &N, &F);
    choice(0);
    for (int i=0;i<N;++i) printf("%d ", a[i]);
}