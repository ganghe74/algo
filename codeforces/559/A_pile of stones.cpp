#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    char x;
    scanf("%d ", &n);
    for (int i=0;i<n;++i) {
        x = getchar();
        if (x == '-') {
            ans--;
            if (ans < 0) ans++;
        }
        if (x == '+') {
            ans++;
        }
    }
    printf("%d", ans);
}