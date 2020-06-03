#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

string s;
int a[10];

int greedy_flip(int pstate, int &state, int &nstate) {
    int cnt = 0;
    for (int i=0;i<10;++i) {
        if (pstate & (1 << i)) {
            cnt++;
            nstate ^= (1 << i);
            state ^= (1 << i);
            if (i-1 >= 0) state ^= (1 << (i-1));
            if (i+1 < 10) state ^= (1 << (i+1));
        }
    }
    return cnt;
}

int solve(int row, int pstate, int state) {
    if (row == 10) {
        if (pstate == 0) return 0;
        return INF;
    }
    int nstate = a[row+1];
    int cnt = greedy_flip(pstate, state, nstate);
    return min(INF, solve(row+1, state, nstate) + cnt);
}

int main() {
    for (int i=0;i<10;++i) {
        cin >> s;
        for (int j=0;j<10;++j)
            if (s[j] == 'O')
                a[i] |= (1<<j);
    }
    int ans = INF;
    for (int pstate=0; pstate<(1<<10); ++pstate) {
        int state = a[0];
        int nstate = a[1];
        int cnt = greedy_flip(pstate, state, nstate);
        ans = min(ans, solve(1, state, nstate) + cnt);
    }
    if (ans == INF) ans = -1;
    cout << ans;
}
