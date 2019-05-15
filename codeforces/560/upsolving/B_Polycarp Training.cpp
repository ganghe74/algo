#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int idx = 0, k = 0;
    while (idx < n) {
        if (k + 1 <= a[idx]) k++;
        idx++;
    }
    printf("%d", k);
}