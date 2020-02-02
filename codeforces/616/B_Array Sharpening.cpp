#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> a(n);
        for (int i=0;i<n;++i) scanf("%d", &a[i]);
        a.push_back(1e9);
        
        int idx = 0;
        bool inc = true;
        while (idx < n) {
            if (inc) {
                if (a[idx+1] <= idx) inc = false;
                else a[idx] = idx;
            }
            else {
                a[idx] = min(a[idx-1] - 1, a[idx]);
                if (a[idx] < 0) break;
            }
            idx++;
        }

        if (a[idx] < 0) puts("No");
        else puts("Yes");
    }
}
// 3
// 5
// 5 1 1 1 1
// 5
// 5 4 3 2 1
// 10
// 1 2 3 4 5 5 1 1 1 1
