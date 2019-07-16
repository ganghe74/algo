#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3][2];
    for (int i=0;i<3;++i) scanf("%d%d", &a[i][0], &a[i][1]);
    if (a[0][0] == a[1][0]) printf("%d ", a[2][0]);
    else if (a[0][0] == a[2][0]) printf("%d ", a[1][0]);
    else printf("%d ", a[0][0]);
    if (a[0][1] == a[1][1]) printf("%d", a[2][1]);
    else if (a[0][1] == a[2][1]) printf("%d", a[1][1]);
    else printf("%d", a[0][1]);
}