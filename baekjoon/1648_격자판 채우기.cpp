#include <bits/stdc++.h>
using namespace std;

int n, m, d[196][1<<14];

int solve(int num, int state) {
    if (num == n*m && state == 0)
        return 1;
    if (num >= n*m)
        return 0;
    int &ret = d[num][state];
    if (ret != -1) return ret;
    if (state & 1) return ret = solve(num+1, state >> 1);
    ret = solve(num+1, (state >> 1) | (1 << (m-1)));
    if (num % m != m-1 && (state & 2) == 0)
        ret += solve(num+2, state >> 2);
    ret %= 9901;
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d%d", &n, &m);
    printf("%d", solve(0, 0));
}
