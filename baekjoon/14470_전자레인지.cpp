#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, t = 0;
    cin >> a >> b >> c >> d >> e;
    if (a < 0) {
        t += -a * c;
        a = 0;
    }
    if (a == 0) t += d;
    t += (b-a) * e;
    printf("%d", t);
}