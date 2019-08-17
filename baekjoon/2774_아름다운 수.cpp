#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, X;
    scanf("%d", &T);
    while (T--) {
        bool c[10] = {};
        int cnt = 0;
        scanf("%d", &X);
        while (X > 0) {
            if (!c[X%10]) {
                c[X%10] = 1;
                cnt++;
            }
            X /= 10;
        }
        printf("%d\n", cnt);
    }
}