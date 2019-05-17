#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char s[101];
    scanf("%d", &n);
    scanf("%s", s);
    for (int len=1;len<25;++len) {
        for (int start=0;start+4*len<n;++start) {
            if ('*' == s[start] && s[start] == s[start + len] && s[start] == s[start + len*2] && s[start] == s[start + len*3] && s[start] == s[start + len*4]) {
                puts("yes");
                return 0;
            }
        }
    }
    puts("no");
}