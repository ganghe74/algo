#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int tc=1;tc<=T;++tc) {
        int x, y, z;
        char o;
        scanf("%d %c %d = %d", &x, &o, &y, &z);
        if (o == '+') {
            if (x + y == z) printf("Case %d: YES\n", tc);
            else printf("Case %d: NO\n", tc);
        }
        else {
            if (x - y == z) printf("Case %d: YES\n", tc);
            else printf("Case %d: NO\n", tc);
        }
    }
}