#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d ", &T);
    for (int t=1;t<=T;++t) {
        char s[21];
        scanf("%s", &s);
        int n = strlen(s);
        vector<int> a(n);
        for (int i=0;i<n;++i) a[i] = i;
        printf("Case # %d:\n", t);
        do {
            for (int x : a) putchar(s[x]);
            puts("");
        }
        while (next_permutation(a.begin(), a.end()));
    }
}