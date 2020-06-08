#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m;
        vector<bool> rowused(n), colused(m);
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j) {
                cin >> x;
                if (x) {
                    rowused[i] = 1;
                    colused[j] = 1;
                }
            }
        int cntr = 0, cntc = 0;
        for (int i=0;i<n;++i)
            if (!rowused[i]) cntr++;
        for (int i=0;i<m;++i)
            if (!colused[i]) cntc++;
        int cnt = min(cntr, cntc);
        cout << ((cnt%2) ? "Ashish" : "Vivek") << '\n';
    }
}
