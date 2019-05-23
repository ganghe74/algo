#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    for (int i=2;i<n;++i) {
        if (a[i-2] + a[i-1] > a[i]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}