#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a[2], b[2];
        scanf("%d%d%d%d", &a[0], &a[1], &b[0], &b[1]);
        bool flag = false;
        for (int i=0;i<2;++i) {
            for (int j=0;j<2;++j) {
                if (a[i] == b[j] && (a[1-i] + b[1-j] == a[i]))
                    flag = true;
            }
        }
        puts(flag ? "YES" : "NO");
    }
}
