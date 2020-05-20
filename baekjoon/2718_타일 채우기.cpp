#include <bits/stdc++.h>
using namespace std;

int t, n, d[100][1<<4];

int solve(int num, int state) {
    if (num == 4*n && !state) return 1;
    if (num >= 4*n) return 0;
    int &ret = d[num][state];
    if (ret != -1) return ret;
    if (state & 1) return ret = solve(num+1, state >> 1);
    ret = solve(num+1, (state >> 1) | (1 << 3));
    if (num % 4 != 3 && !(state & 2)) ret += solve(num+2, state >> 2);
    return ret;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(d, -1, sizeof(d));
        scanf("%d", &n);
        printf("%d\n", solve(0, 0));
    }
}
