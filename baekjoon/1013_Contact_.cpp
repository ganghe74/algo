#include <bits/stdc++.h>
using namespace std;

int d[10][2] = {
    {7, 1},
    {2, 9},
    {3, 9},
    {3, 4},
    {7, 5},
    {6, 5},
    {3, 8},
    {9, 8},
    {7, 1},
    {9, 9}
};

int main() {
    int T;
    char s[201];
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int status = 0;
        for (int i=0;s[i]!='\0';++i) {
            status = d[status][s[i]-'0'];
        }
        if (status == 4 || status == 5 || status == 8) puts("YES");
        else puts("NO");
    }
}