#include <bits/stdc++.h>
using namespace std;
bool c[26];
int main() {
    int start[26], end[26];
    int ans = 0;
    char s[53];
    scanf("%s", s);
    for (int i=0;i<52;++i) {
        if (c[s[i]-'A']) {
            end[s[i]-'A'] = i;
        }
        else {
            c[s[i]-'A'] = 1;
            start[s[i]-'A'] = i;
        }
    }
    for (int i=0;i<26;++i) {
        for (int j=0;j<26;++j) {
            if (start[i] < start[j] && start[j] < end[i] && end[i] < end[j]) ans++;
        }
    }
    printf("%d", ans);
}