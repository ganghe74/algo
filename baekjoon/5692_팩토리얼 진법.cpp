#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        int ans = 0;
        for (int i=5;i>0;--i) {
            ans += n % (int)pow(10, i) / pow(10, i-1);
            ans *= i;
        }
        printf("%d\n", ans);
    }
}