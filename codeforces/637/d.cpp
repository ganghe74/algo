#include <bits/stdc++.h>
using namespace std;

int N, k, a[2001], d[2001][2001];
int transition[1<<7][8];
pair<int,int> p[2001][2001];

int to_num(int status) {
    vector<int> numtable = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
    for (int i=0;i<10;++i)
        if (status == numtable[i])
            return i;
    return -1;
}

int max_transition(int status, int k) {
    int &ret = transition[status][k];
    if (!k) return ret = to_num(status);
    if (ret != 100) return ret;
    ret = -1;
    for (int i=0;i<8;++i) {
        if (!(status & (1 << i)))
            ret = max(ret, max_transition(status | (1 << i), k-1));
    }
    return ret;
}

int solve(int n, int k) {
    if (n == N) return (k == 0);
    int &ret = d[n][k];
    if (ret != -1) return ret;

    int status = a[n];
    int bits = __builtin_popcount(status);
    int max_num = -1;
    ret = 0;

    for (int i=0;i<=min(k,7-bits);++i) {
        int num = max_transition(status, i);
        if (num != -1) {
            if (solve(n+1, k-i)) {
                ret = 1;
                if (num > max_num) {
                    max_num = num;
                    p[n][k] = {n+1, k-i};
                }
            }
        }
    }
    return ret;
}

void trace(int n, int k) {
    if (n == N) return;
    auto [nn, nk] = p[n][k];
    printf("%d", max_transition(a[n], k-nk));
    trace(n+1, nk);
}

int main() {
    memset(d, -1, sizeof(d));
    for (int i=0;i<(1<<7);++i)
        for (int j=0;j<8;++j)
            transition[i][j] = 100;

    scanf("%d%d", &N, &k);
    for (int i=0;i<N;++i) {
        int x, status = 0;
        for (int i=0;i<7;++i) {
            scanf("%1d", &x);
            status = (status << 1) + x;
        }
        a[i] = status;
    }

    int possible = solve(0, k);
    if (possible) trace(0, k);
    else puts("-1");
}
