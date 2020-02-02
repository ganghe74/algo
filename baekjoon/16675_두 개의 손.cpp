#include <bits/stdc++.h>
using namespace std;
int main() {
    char a, b, c, d;
    scanf("%c %c %c %c", &a, &b, &c, &d);
    if (a == b && c == d) {
        if (a == c) puts("?");
        else if ((a == 'R' && c == 'S') || (a == 'S' && c == 'P') || (a == 'P' && c == 'R')) puts("MS");
        else puts("TK");
    }
    else if (a == b) {
        if (a == 'R' && (c == 'P' || d == 'P')) puts("TK");
        else if (a == 'S' && (c == 'R' || d == 'R')) puts("TK");
        else if (a == 'P' && (c == 'S' || d == 'S')) puts("TK");
        else puts("?");
    }
    else if (c == d) {
        if (c == 'R' && (a == 'P' || b == 'P')) puts("MS");
        else if (c == 'S' && (a == 'R' || b == 'R')) puts("MS");
        else if (c == 'P' && (a == 'S' || b == 'S')) puts("MS");
        else puts("?");
    }
    else puts("?");
}
