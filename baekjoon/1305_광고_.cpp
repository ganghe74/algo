#include <bits/stdc++.h>
using namespace std;
int n, fail[1000001];
char s[1000001];
int main() {
    scanf("%d %s", &n, s);
    for (int i=1, j=0;i<n;++i) {
        while (j && s[i] != s[j]) j = fail[j-1];
        if (s[i] == s[j]) fail[i] = ++j;
    }
    printf("%d", n-fail[n-1]);
}