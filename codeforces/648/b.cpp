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
        bool has0 = false, has1 = false;
        for (int i=0;i<n;++i) cin >> a[i];
        for (int i=0;i<n;++i) {
            cin >> b[i];
            if (b[i] == 0) has0 = true;
            else has1 = true;
        }
        bool sorted = true;
        for (int i=1;i<n;++i)
            if (a[i-1] > a[i]) sorted = false;
        if ((has0 && has1) || sorted) cout << "Yes\n";
        else cout << "No\n";
    }
}
