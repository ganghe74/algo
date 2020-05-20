#include <bits/stdc++.h>
using namespace std;

int dmin[2501][1<<4][51], dmax[2501][1<<4][51];
string s, subs[4];

pair<int,int> solve(int idx, int state, int filled) {
    if (!state)
        return {0, 0};
    if (idx >= s.size())
        return {1e9, -1e9};
    int &retmin = dmin[idx][state][filled];
    int &retmax = dmax[idx][state][filled];
    if (retmin != -1)
        return {retmin, retmax};
    tie(retmin, retmax) = solve(idx+1, state, max(filled-1, 0));
    for (int i=0; i<4; ++i) {
        if (state & (1<<i)) {
            if (s.substr(idx, subs[i].size()) == subs[i]) {
                int nextc = 0;
                if (subs[i].size() > filled)
                    nextc = (int)subs[i].size() - filled;
                auto [tmin, tmax] = solve(idx, state - (1<<i), max((int)subs[i].size(), filled));
                retmin = min(retmin, tmin + nextc);
                retmax = max(retmax, tmax + nextc);
            }
        }
    }
    return {retmin, retmax};
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    memset(dmin, -1, sizeof(dmin));
    memset(dmax, -1, sizeof(dmax));
    cin >> s >> subs[0] >> subs[1] >> subs[2] >> subs[3];

    auto [mi, ma] = solve(0, 0b1111, 0);
    cout << mi << ' ' << ma;
}
