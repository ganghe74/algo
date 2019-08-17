#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[9];
    for (int t=0;t<3;++t) {
        scanf("%s", s);
        int ans = 0, cnt = 0;
        for (int i=0;i<8;++i) {
            if (s[i] == s[i+1]) cnt++;
            else {
                ans = max(ans, cnt+1);
                cnt = 0;
            }
        }
        printf("%d\n", ans);
    }
}