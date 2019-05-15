#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        char s[101];
        scanf("%d ", &n);
        scanf("%s", s);

        int idx_8 = -1;
        for (int i=0;i<n;++i) {
            if (s[i] == '8') {
                idx_8 = i;
                break;
            }
        }
        if (idx_8 != -1 && idx_8 + 10 < n) puts("YES");
        else puts("NO");
    }
}