#include <bits/stdc++.h>
using namespace std;

int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        int n, cnt = 0;
        scanf("%d", &n);
        for (int i=1;i<=n;++i)
            if (n % i == 0) cnt++;
        printf("%d %d\n", n, cnt);
    }
}