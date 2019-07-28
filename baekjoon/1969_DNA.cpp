#include <bits/stdc++.h>
using namespace std;
int cnt[50][4];
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        char s[51];
        scanf("%s", s);
        for (int i=0;i<s[i]!='\0';++i) {
            if (s[i] == 'A') cnt[i][0]++;
            if (s[i] == 'C') cnt[i][1]++;
            if (s[i] == 'G') cnt[i][2]++;
            if (s[i] == 'T') cnt[i][3]++;
        }
    }
    int d = 0;
    for (int i=0;i<M;++i) {
        int m = 0;
        for (int j=0;j<4;++j) {
            if (cnt[i][j] > cnt[i][m]) m = j;
        }
        putchar("ACGT"[m]);
        d += N - cnt[i][m];
    }
    printf("\n%d", d);
}