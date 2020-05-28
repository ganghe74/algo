#include <bits/stdc++.h>
using namespace std;

int tc, k, n;
string a[15];
int d[15][1<<15], overlap[15][15];

int restore(int last, int used) {
    if (used == (1<<n)-1) return 0;
    int &ret = d[last][used];
    if (ret != -1) return ret;
    ret = 0;
    for (int next=0; next<n; ++next) {
        if ((used & (1<<next)) == 0) {
            int cand = overlap[last][next] + restore(next, used | (1<<next));
            ret = max(ret, cand);
        }
    }
    return ret;
}

string reconstruct(int last, int used) {
    if (used == (1<<n)-1) return "";
    for (int next=0; next<n;++next) {
        if (used & (1<<next)) continue;
        int ifUsed = overlap[last][next] + restore(next, used | (1<<next));
        if (restore(last, used) == ifUsed)
            return (a[next].substr(overlap[last][next]) + reconstruct(next, used | (1 << next)));
    }
    return "****oops****";
}

int main() {
    cin >> tc;
    while (tc--) {
        memset(d, -1, sizeof(d));
        cin >> k;
        for (int i=0;i<k;++i)
            cin >> a[i];

        while (true) {
            bool removed = false;
            for (int i=0;i<k&&!removed;++i) {
                for (int j=0;j<k;++j) {
                    if (i != j && a[i].find(a[j]) != -1) {
                        a[j] = a[k-1];
                        k--;
                        removed = true;
                    }
                }
            }
            if (!removed) break;
        }
        n = k;

        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                if (i == j) continue;
                int len = min(a[i].size(), a[j].size());
                while (len >= 0) {
                    if (a[i].substr(a[i].size()-len) == a[j].substr(0, len)) {
                        overlap[i][j] = len;
                        break;
                    }
                    len--;
                }
            }
        }
        int start = 0;
        for (int i=1;i<n;++i)
            if (restore(i, 1<<i) > restore(start, 1<<start))
                start = i;
        string ans = a[start] + reconstruct(start, 1<<start);
        cout << ans << '\n';
    }
}
