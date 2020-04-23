#include <bits/stdc++.h>
using namespace std;

int tc, n, x, p[100001];

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i=0;i<n;++i) {
            scanf("%d", &x);
            p[x-1] = i;
        }
        bool flag = true;
        vector<bool> used(n+1);
        used[n] = true;

        int idx = 0;
        while (idx < n) {
            int pos = p[idx];
            while (!used[pos]) {
                if (pos != p[idx]) {
                    flag = false;
                    break;
                }
                used[pos] = 1;
                idx++; pos++;
            }
            if (!flag) break;
        }

        if (flag) puts("Yes");
        else puts("No");

    }
}
