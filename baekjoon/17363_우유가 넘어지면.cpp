#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    char s[100][101];
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) scanf("%s", s[i]);
    for (int i=M-1;i>=0;--i) {
        for (int j=0;j<N;++j) {
            char x = s[j][i];
            if (x == '-') putchar('|');
            else if (x == '|') putchar('-');
            else if (x == '/') putchar('\\');
            else if (x == '\\') putchar('/');
            else if (x == '^') putchar('<');
            else if (x == '<') putchar('v');
            else if (x == 'v') putchar('>');
            else if (x == '>') putchar('^');
            else putchar(x);
        }
        puts("");
    }
}