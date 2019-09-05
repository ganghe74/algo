#include <bits/stdc++.h>
using namespace std;
int a[5000], w, n;
bool mark[800000];
int main() {
    scanf("%d%d", &w, &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    for (int k=0;k<n;++k) {
        for (int i=0;i<k-1;++i) mark[a[i]+a[k-1]] = 1;
        for (int l=k+1;l<n;++l) {
            if (w-a[k]-a[l] > 0) {
                if (mark[w-a[k]-a[l]]) {
                    puts("YES");
                    return 0;
                }
            }
        }
    }
    puts("NO");
}