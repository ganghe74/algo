#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];

int main() {
    a[3] = 0; a[4] = 1;
    scanf("%d", &n);
    for (int i=5;i<=n;++i) a[i] = a[(i+1)/2] + 2;
    printf("%d", a[n]);
}