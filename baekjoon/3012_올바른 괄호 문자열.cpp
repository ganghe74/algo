#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MOD = 1e5;
int N;
char s[201];
char open[] = "({[";
char close[] = ")}]";
lint d[200][200];

lint solve(int i, int j) {
    if (i > j) return 1;
    lint &ret = d[i][j];
    if (ret != -1) return ret;
    ret = 0;
    for (int k=i+1;k<=j;k+=2) {
        for (int l=0;l<3;++l) {
            if (s[i] == open[l] || s[i] == '?') {
                if (s[k] == close[l] || s[k] == '?') {
                    lint tmp = solve(i+1,k-1) * solve(k+1, j);
                    ret += tmp;
                    if (ret >= MOD) {
                        ret = MOD + ret % MOD;
                    }
                }
            }
        }
    }
    return ret;
}

int main() {
    memset(d, -1, sizeof(d));
    scanf("%d %s", &N, s);
    lint ans = solve(0, N-1);
    if (ans >= MOD) printf("%05lld", ans % MOD);
    else printf("%lld", ans);
}