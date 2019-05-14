#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, ans = 0;
    scanf("%d%d%d", &n, &x, &y);
    char s[200005];
    scanf("%s", s);
    for (int i=n-1;i>n-1-x;--i) {
        if (i == n-1-y) {
            if (s[i] == '0') ans++;
        }
        else {
            if (s[i] == '1') ans++;
        }
    }
    printf("%d", ans);
}