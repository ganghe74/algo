#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int cnt1[26] = {}, cnt2[26] = {};
        char s1[1001], s2[1001];
        scanf("%s %s", s1, s2);
        for (int i=0;s1[i]!='\0';++i) cnt1[s1[i]-'a']++;
        for (int i=0;s2[i]!='\0';++i) cnt2[s2[i]-'a']++;
        bool possible = true;
        for (int i=0;i<26;++i) {
            if (cnt1[i] != cnt2[i]) {
                possible = false;
                break;
            }
        }
        if (possible) puts("Possible");
        else puts("Impossible");
    }
}