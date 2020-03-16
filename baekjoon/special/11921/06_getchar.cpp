#include <bits/stdc++.h>
using namespace std;

int n, x;

int getu() {
    int ret = 0;
    char c = getchar();
    while (c == ' ' || c == '\n') c = getchar();
    while ('0' <= c && c <= '9') {
        ret = ret * 10 + c - 48;
        c = getchar();
    }
    return ret;
}

int geti() {
    int ret = 0, sign = 1;
    char c = getchar();
    while (c == ' ' || c == '\n') c = getchar();
    if (c == '-') sign = -1, c = getchar();
    while ('0' <= c && c <= '9') {
        ret = ret * 10 + c - 48;
        c = getchar();
    }
    return sign * ret;
}

int main() {
    n = getu();
    printf("%d\n", n);
    while (n--) {
        x = getu();
        printf("%d\n", x);
    }
}
