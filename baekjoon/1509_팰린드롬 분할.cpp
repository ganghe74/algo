#include <iostream>
#include <cstring>
using namespace std;
char s[2502];
int c[2501][2501];
int d[2501];
int main() {
    scanf("%s", s+1);
    int n = strlen(s+1);
    for (int i=1;i<=n;++i) c[i][i] = 1;
    for (int i=1;i<=n-1;++i) c[i][i+1] = (s[i] == s[i+1]);
    for (int k=3;k<=n;++k) {
        for (int i=0;i+k-1<=n;++i) {
            c[i][i+k-1] = c[i+1][i+k-2] && (s[i] == s[i+k-1]);
        }
    }
    d[0] = 0;
    for (int i=1;i<=n;++i) {
        d[i] = -1;
        for (int j=1;j<=i;++j) {
            if (c[j][i]) {
                if (d[i] == -1 || d[i] > d[j-1] + 1) {
                    d[i] = d[j-1] + 1;
                }
            }
        }
    }
    printf("%d", d[n]);
}