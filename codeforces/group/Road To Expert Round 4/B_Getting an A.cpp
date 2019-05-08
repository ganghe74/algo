#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a+n);

    int idx = 0, ans = 0;

    while (sum < n * 4.5) {
        sum += 5-a[idx++];
        ans++;
    }

    printf("%d", ans);
}