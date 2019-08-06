#include <bits/stdc++.h>
using namespace std;

char s[100][101];
int main() {
    int N, K;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%s", s[i]);
    scanf("%d", &K);
    if (K == 1) {
        for (int i=0;i<N;++i) printf("%s\n", s[i]);
    }
    else if (K == 2) {
        for (int i=0;i<N;++i) {
            for (int j=N-1;j>=0;--j) printf("%c", s[i][j]);
            puts("");
        }
    }
    else {
        for (int i=N-1;i>=0;--i) printf("%s\n", s[i]);
    }
}