#include <bits/stdc++.h>
using namespace std;
int main() {
    int h1, m1, h2, m2, n, t1, t2, cnt=0;
    scanf("%d%d%d%d%d", &h1, &m1, &h2, &m2, &n);
    t1 = h1 * 60 + m1; t2 = h2 * 60 + m2;
    while (t1 <= t2) {
        if (t1 % 10 == n || t1 % 60 / 10 == n || t1 / 60 % 10 == n || t1 / 60 /10 == n) cnt++;
        t1++;
    }
    printf("%d", cnt);
}