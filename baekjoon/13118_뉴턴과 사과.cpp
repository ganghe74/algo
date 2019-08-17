#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, p[4];
    for (int i=0;i<4;++i) scanf("%d", &p[i]);
    scanf("%d", &x);
    for (int i=0;i<4;++i) {
        if (p[i] == x) {
            printf("%d", i+1);
            return 0;
        }
    }
    puts("0");
}