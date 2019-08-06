#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[50][51];
    int R, C, ZR, ZC;
    scanf("%d%d%d%d", &R, &C, &ZR, &ZC);
    for (int i=0;i<R;++i) scanf("%s", s[i]);
    for (int i=0;i<R;++i) {
        for (int j=0;j<ZR;++j) {
            for (int k=0;k<C;++k) {
                for (int l=0;l<ZC;++l) putchar(s[i][k]);
            }
            puts("");
        }
    }
}