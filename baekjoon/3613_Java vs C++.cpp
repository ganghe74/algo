#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[101];
    scanf("%s", s);
    int n = strlen(s);
    bool cpp = false, java = false;
    for (int i=0;i<n;++i) {
        if (s[i] == '_') cpp = true;
        if (isupper(s[i])) java = true;
    }
    if (cpp && java) puts("Error!");
    else if (!cpp && !java) puts(s);
    else {
        if (!islower(s[0]) || s[n-1] == '_') {
            puts("Error!");
            return 0;
        }
        for (int i=0;i<n-1;++i) {
            if (s[i] == '_' && s[i] == s[i+1]) {
                puts("Error!");
                return 0;
            }
        }
        if (cpp) {
            for (int i=0;i<n;++i) {
                if (s[i] == '_') {
                    putchar(toupper(s[++i]));
                }
                else putchar(s[i]);
            }
        }
        else {
            for (int i=0;i<n;++i) {
                if (isupper(s[i])) putchar('_');
                putchar(tolower(s[i]));
            }
        }
    }
}