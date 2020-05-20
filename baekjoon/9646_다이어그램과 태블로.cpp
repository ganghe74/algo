#include <bits/stdc++.h>
using namespace std;

int k, n, d[7][825000];
vector<int> shape;

int v2n(const vector<int> &v) {
    if (v[0] == -1) return 0;
    int ret = 0;
    for (int i=v.size()-1;i>=0;--i)
        ret = ret * 7 + v[i];
    return ret;
}

int solve(int row, vector<int> pstate) {
    if (row == k) return 1;
    int &ret = d[row][v2n(pstate)];
    if (ret != -1) return ret;
    ret = 0;
    vector<int> state = pstate;
    state.resize(shape[row]);
    for (auto &e : state)
        if (++e >= n)
            return 0;
    do {
        ret += solve(row+1, state);
        state.back()++;
        for (int i=state.size()-1; i >= 1 && state[i] >= n; --i)
            state[i-1]++;
        for (int i=1; i < state.size(); ++i)
            if (state[i] >= n)
                state[i] = max(state[i-1], pstate[i] + 1);
    } while (state[0] < n);
    return ret;
}

int main() {
    while (scanf("%d", &k) == 1) {
        memset(d, -1, sizeof(d));
        shape.resize(k);
        for (int i=0;i<k;++i)
            scanf("%d", &shape[i]);
        scanf("%d", &n);
        printf("%d\n", solve(0, vector<int>(shape[0], -1)));
    }
}
