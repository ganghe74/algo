#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n == 1) puts("-1");
        else {
            for (int i=0;i<n-1;++i) putchar('7');
            puts("8");
        }
    }
}
