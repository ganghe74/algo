#include <bits/stdc++.h>
using namespace std;
#define BS 524288

int n, x;
char buf[BS];

char getc() {
    static int idx = BS;
    if (idx == BS) {
        fread(buf, 1, BS, stdin);
        idx = 0;
    }
    return buf[idx++];
}

int getu() {
    int ret = 0;
    char c = getc();
    while (c == ' ' || c == '\n') c = getc();
    while ('0' <= c && c <= '9') {
        ret = ret * 10 + c - 48;
        c = getc();
    }
    return ret;
}

int geti() {
    int ret = 0, sign = 1;
    char c = getc();
    while (c == ' ' || c == '\n') c = getc();
    if (c == '-') sign = -1, c = getc();
    while ('0' <= c && c <= '9') {
        ret = ret * 10 + c - 48;
        c = getc();
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
