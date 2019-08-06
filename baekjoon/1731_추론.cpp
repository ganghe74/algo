#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
lint n, a[50];
int main() {
    cin >> n;
    for (int i=0;i<n;++i) cin >> a[i];
    if (a[2] * a[0] == a[1] * a[1]) cout << a[n-1] * a[1] / a[0];
    else cout << a[n-1] + a[1] - a[0];
}