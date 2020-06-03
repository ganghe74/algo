#include <bits/stdc++.h>
using namespace std;

int d[100][1<<20];
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

int solve(int num, int state) {
    if (num == 100) {
        if ((state & ((1<<10)-1))) return 1e9;
        return 0;
    }
    int &ret = d[num][state];
    if (ret != -1) return ret;

    int r = num / 10;
    int c = num % 10;

    // THIS CODE RAISE TLE
    // int t1 = solve(num+1, get_nstate(state, r, c, true)) + 1;
    // int t2 = solve(num+1, get_nstate(state, r, c, false));
    // if (!r) ret = min(t1, t2);
    // else if (state & 1) ret = t1;
    // else ret = t2;

    if (!r) ret = min(solve(num+1, get_nstate(state, r, c, true)) + 1, solve(num+1, get_nstate(state, r, c, false)));
    else if (state & 1) ret = solve(num+1, get_nstate(state, r, c, true)) + 1;
    else ret = solve(num+1, get_nstate(state, r, c, false));

    return ret;
}

void print_bin(int n) {
    string s(20, '0');
    for (int i=0;i<20;++i)
        if (n & (1<<i))
            s[i] = '1';
    for (int i=0;i<4;++i)
        printf("%s ", s.substr(i*5, 5).c_str());
    puts("");
}

int main() {
    memset(d, -1, sizeof(d));
    for (int i=0;i<10;++i)
        cin >> a[i];
    int state = 0;
    for (int i=0;i<10;++i)
        if (a[0][i] == 'O') state |= (1<<i);
    // print_bin(state);
    state <<= 10;
    // print_bin(state);
    // print_bin(get_nstate(state, 0, 0, true));
    // print_bin(get_nstate(state, 0, 0, false));
    printf("%d\n", solve(0, state));
}
