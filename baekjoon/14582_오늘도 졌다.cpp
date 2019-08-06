#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[2][9];
    for (int i=0;i<2;++i) {
        for (int j=0;j<9;++j) scanf("%d", &a[i][j]);
    }
    int s1 = 0, s2 = 0;
    bool w = 0;
    for (int i=0;i<9;++i) {
        s1 += a[0][i];
        if (s1 > s2) w = 1;
        s2 += a[1][i];
    }
    if (w) puts("Yes");
    else puts("No");
}