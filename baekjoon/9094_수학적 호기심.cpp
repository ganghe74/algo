#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        int cnt = 0;
        for (int b=2;b<n;++b) {
            for (int a=1;a<b;++a) {
                if ((a*a+b*b+m)%(a*b) == 0) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}