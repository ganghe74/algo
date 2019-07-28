#include <iostream>
#include <cstring>
using namespace std;
int d[1001][1001];
int main() {
    char s1[1001], s2[1001];
    scanf("%s %s", s1, s2);
    int l1 = strlen(s1), l2 = strlen(s2), ans = 0;
    for (int i=1;i<=l1;++i) {
        for (int j=1;j<=l2;++j) {
            if (s1[i-1] == s2[j-1]) {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
            ans = max(ans, d[i][j]);
        }
    }
    printf("%d", ans);
}