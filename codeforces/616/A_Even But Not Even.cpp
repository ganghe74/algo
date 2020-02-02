#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N;
    char s[3001];
    bool c[3001];
    scanf("%d", &T);
    while (T--) {
        memset(c, 0, sizeof(c));
        scanf("%d %s", &N, s);
        int len = N, sum = 0;
        
        for (int i=0;i<N;++i) sum += s[i] - '0';
        for (int i=0;i<N;++i) {
            if (s[i] == '0') {
                c[i] = 1;
                len--;
            }
        }

        int last;
        for (int i=N-1;i>=0;--i) {
            if (!c[i]) {
                if ((s[i] - '0') % 2 == 1) {
                    last = i;
                    break;
                }
                c[i] = 1;
                sum -= s[i] - '0';
                len--;
            }
        }

        for (int i=0;i<last;++i) {
            if (sum % 2 == 0) break;
            if (!c[i]) {
                if ((s[i] -'0') % 2) {
                    c[i] = 1;
                    sum -= s[i] - '0';
                    len--;
                }
            }
        }
        
        if (len == 0 || sum % 2 == 1) puts("-1");
        else {
            for (int i=0;i<N;++i) {
                if (!c[i]) putchar(s[i]);
            }
            puts("");
        }

    }
}
