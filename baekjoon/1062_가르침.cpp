#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
char s[50][16];
vector<int> a(26);

int count() {
    int ret = N;
    for (int i=0;i<N;++i) {
        for (int j=0;s[i][j]!='\0';++j) {
            if (!a[s[i][j]-'a']) {
                ret--;
                break;
            }
        }
    }
    return ret;
}

void choice(int idx, int cnt) {
    if (cnt > K) return;
    if (cnt == K) {
        ans = max(ans, count());
        return;
    }
    for (int i=idx;i<26;++i) {
        if (a[i]) continue;
        a[i] = 1;
        choice(i+1, cnt+1);
        a[i] = 0;
    }
}

int main() {
    a[0]=1; a[2]=1; a[8]=1; a[13]=1; a[19]=1;
    scanf("%d%d", &N, &K);
    for (int i=0;i<N;++i) scanf("%s", s[i]);
    choice(0, 5);
    printf("%d", ans);
}