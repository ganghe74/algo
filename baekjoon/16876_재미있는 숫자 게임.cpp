#include <bits/stdc++.h>
using namespace std;

int n, m, d[100][10000];
int po10[] = {1, 10, 100, 1000};

int solve(int turn, int num) {
    if (turn == m)
        return num > n;
    int &ret = d[turn][num];
    if (ret != -1)
        return ret;
    ret = (turn % 2) ? 1 : 0;
    for (int pos=0; pos<4; ++pos) {
        int digit = num / po10[pos] % 10;
        int nnum = num - digit * po10[pos] + ((digit+1)%10) * po10[pos];
        if (turn % 2) ret &= solve(turn+1, nnum);
        else ret |= solve(turn+1, nnum);
    }
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &n, &m);
    if (solve(0, n)) puts("koosaga");
    else puts("cubelover");
}
