#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int main() {
    int M;
    scanf("%d", &M);
    lint rpm = 1, twist = 0;
    while (M--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        rpm = rpm * b / a;
        twist += c;
    }
    printf("%lld %lld", twist % 2, rpm);
}