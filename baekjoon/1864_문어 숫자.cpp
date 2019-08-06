#include <bits/stdc++.h>
using namespace std;

int f(char x) {
    if (x == '-') return 0;
    if (x == '\\') return 1;
    if (x == '(') return 2;
    if (x == '@') return 3;
    if (x == '?') return 4;
    if (x == '>') return 5;
    if (x == '&') return 6;
    if (x == '%') return 7;
    return -1;
}

int main() {
    char s[9];
    while (true) {
        scanf("%s", s);
        if (s[0] == '#') break;
        int n = 0;
        for (int i=0;s[i]!='\0';++i) {
            n *= 8;
            n += f(s[i]);
        }
        printf("%d\n", n);
    }
}