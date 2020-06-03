#include <bits/stdc++.h>
using namespace std;

int8_t d[100][1<<20];
string a[10];

int get_nstate(int state, int r, int c, bool flip) {
    int nstate = state >> 1;
    if (r+1 < 10 && a[r+1][c] == 'O') nstate |= (1 << 19);
    if (flip) {
        nstate ^= (1 << 9);
        nstate ^= (1 << 19);
        if (c-1 >= 0)
            nstate ^= (1 << 8);
        if (c+1 < 10)
            nstate ^= (1 << 10);
    }
    return nstate;
}

int8_t solve(int num, int state) {
    if (num == 100) {
        if ((state & ((1<<10)-1))) return 100;
        return 0;
    }
    auto &ret = d[num][state];
    if (ret != -1) return ret;

    int r = num / 10;
    int c = num % 10;

    if (!r) ret = min((int8_t)(solve(num+1, get_nstate(state, r, c, true)) + 1), solve(num+1, get_nstate(state, r, c, false)));
    else if (state & 1) ret = solve(num+1, get_nstate(state, r, c, true)) + 1;
    else ret = solve(num+1, get_nstate(state, r, c, false));
    ret = min((int8_t)100, ret);

    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    for (int i=0;i<10;++i)
        cin >> a[i];
    int state = 0;
    for (int i=0;i<10;++i)
        if (a[0][i] == 'O') state |= (1<<i);
    state <<= 10;
    cout << int(solve(0, state));
}
