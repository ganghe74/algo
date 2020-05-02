#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, a, b;
    scanf("%d%d%d", &k, &a, &b);
    int i = 0;
    while (i < 2000) {
        i += k;
        if (a <= i && i <= b) {
            puts("OK");
            return 0;
        }
    }
    puts("NG");
}
