#include <bits/stdc++.h>
using namespace std;
int main() {
    int len = 0;
    char s[81];
    while (scanf("%s", s) != EOF) {
        if (s[0] == '<') {
            if (s[1] == 'b') {
                puts("");
            }
            else {
                if (len != 0) puts("");
                puts("--------------------------------------------------------------------------------");
            }
            len = 0;
            continue;
        }
        int n = strlen(s);
        if (len + n > 80) {
            len = 0;
            puts("");
        }
        printf("%s ", s);
        len += n + 1;
    }
}