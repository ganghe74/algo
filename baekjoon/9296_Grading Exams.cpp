#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, L;
    char s1[101], s2[101];
    scanf("%d", &T);
    for (int tc=1;tc<=T;++tc) {
        scanf("%d ", &L);
        scanf("%s %s", s1, s2);
        int cnt = 0;
        for (int i=0;i<L;++i) {
            if (s1[i] != s2[i]) cnt++;
        }
        printf("Case %d: %d\n", tc, cnt);
    }

}