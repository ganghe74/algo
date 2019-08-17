#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    vector<int> a(N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int l=0, r=N-1, m=2e9+1, ma=0, mb=0;
    while (l < r) {
        if (abs(a[l]+a[r]) < m) {
            m = abs(a[l]+a[r]);
            ma = a[l];
            mb = a[r];
        }
        if (abs(a[l]+a[r-1]) < abs(a[l+1]+a[r])) r--;
        else l++;
    }
    printf("%d %d", ma, mb);
}