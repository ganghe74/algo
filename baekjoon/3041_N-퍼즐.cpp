#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    char c;
    for (int i=0;i<16;++i) {
        scanf(" %c", &c);
        if (c == '.') continue;
        c -= 'A';
        ans += abs(c/4 - i/4) + abs(c%4 - i%4);
    }
    printf("%d", ans);
}
