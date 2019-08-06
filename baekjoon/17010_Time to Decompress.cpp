#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, n;
    char x;
    scanf("%d", &L);
    while (L--) {
        scanf("%d %c", &n, &x);
        while (n--) putchar(x);
        puts("");
    }
}