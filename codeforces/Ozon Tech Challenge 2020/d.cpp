#include <bits/stdc++.h>
using namespace std;

int n, x, y, degree[1001];
vector<int> a[1001];

int main() {
    cin >> n;
    for (int i=1;i<n;++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }

    for (int i=0;i<n/2;++i) {
        int u = 0, v = 0, w;
        for (int i=1;i<=n;++i) {
            if (degree[i] == 1) {
                if (u) {
                    v = i;
                    break;
                }
                else u = i;
            }
        }
        cout << "? " << u << ' ' << v << endl;
        cout.flush();
        cin >> w;

        if (u == w || v == w) {
            cout << "! " << w << endl;
            cout.flush();
            return 0;
        }

        for (int x : a[u])
            degree[x]--;
        for (int x : a[v])
            degree[x]--;
        degree[u] = degree[v] = -1000;
    }

    for (int i=1;i<=n;++i)
        if (degree[i] == 0) {
            cout << "! " << i << endl;
            cout.flush();
            break;
        }
}
