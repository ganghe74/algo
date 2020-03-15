#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int T, n, need[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
map<int, lint> m;

int main() {
    for (int i=2;i<=100;++i) m[i] = 9e18;
    for (int i=0;i<=15;++i) {
        for (int j=1;j<1000;++j) {
            string s = to_string(j) + string(i, '8');
            int cnt = 0;
            for (char c : s) cnt += need[c-'0'];
            m[cnt] = min(m[cnt], stoll(s));
        }
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%lld ", m[n]);
        if (n%2) {
            putchar('7');
            n-=3;
        }
        while (n > 0) {
            putchar('1');
            n-=2;
        }
        puts("");
    }
}
