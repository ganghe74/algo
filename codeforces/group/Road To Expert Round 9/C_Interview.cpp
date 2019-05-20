#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int a[1000], b[1000];
    cin >> n;
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<n;++i) cin >> b[i];
    int fa = a[0], fb = b[0];
    for (int i=1;i<n;++i) {
        fa = fa | a[i];
        fb = fb | b[i];
    }
    cout << fa + fb;
}