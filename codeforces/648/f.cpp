#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i=0;i<n;++i) cin >> a[i];
        for (int i=0;i<n;++i) cin >> b[i];
        unordered_map<int, unordered_map<int,int>> m;
        for (int i=0;i<n/2;++i) {
            int u = a[i];
            int v = a[n-i-1];
            m[u][v]++; m[v][u]++;
        }
        bool f = true;
        for (int i=0;i<n/2;++i) {
            int u = b[i];
            int v = b[n-i-1];
            if (!m[u][v]) {
                f = false;
                break;
            }
            m[u][v]--; m[v][u]--;
        }
        if (n % 2 == 1 && a[n/2] != b[n/2]) f = false;
        cout << (f ? "yes" : "No") << '\n';
    }
}
