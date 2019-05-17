#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[501];
    char x = 'a';
    bool ok = true;
    scanf("%s", s);
    for (int i=0;s[i]!='\0';++i) {
        if (s[i] == x) x++;
        if (s[i] > x) {
            ok = false;
            break;
        }
    }
    puts(ok?"YES":"NO");
}