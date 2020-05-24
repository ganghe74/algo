#include <bits/stdc++.h>
using namespace std;
int t, n, x, a[50];
int main() {
    scanf("%d", &t);
    while (t--) {
        int o=0, e=0;
        bool haspair = false;
        scanf("%d", &n);
        for (int i=0;i<n;++i) {
            scanf("%d", &a[i]);
            if (a[i] % 2) o++;
            else e++;
        }
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                if (abs(a[i]-a[j]) == 1)
                    haspair = true;
            }
        }
        if ((o%2 == 0 && e%2 == 0) || (o%2 == 1 && e%2 == 1 && haspair)) puts("YES");
        else puts("NO");
    }
}
