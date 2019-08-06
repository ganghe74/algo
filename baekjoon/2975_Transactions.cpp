#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int a, b;
        char x;
        scanf("%d %c %d", &a, &x, &b);
        if (a == 0 && b == 0 && x == 'W') break;
        if (x == 'D') {
            printf("%d\n", a+b);
        }
        else {
            if (a-b >= -200) printf("%d\n", a-b);
            else puts("Not allowed");
        }
    }
}