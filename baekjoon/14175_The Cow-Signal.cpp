#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[11][11];
    int M, N, K;
    scanf("%d%d%d", &M, &N, &K);
    for (int i=0;i<M;++i) scanf("%s", s[i]);
    for (int i=0;i<M;++i) {
        for (int j=0;j<K;++j) {
            for (int k=0;k<N;++k) {
                for (int l=0;l<K;++l) putchar(s[i][k]);
            }
            puts("");
        }
    }
}