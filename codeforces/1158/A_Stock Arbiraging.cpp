#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, m, r, stock;
    scanf("%d%d%d", &n, &m, &r);
    
    int s[n], b[m];

    for (int i=0;i<n;++i) scanf("%d", &s[i]);
    for (int i=0;i<m;++i) scanf("%d", &b[i]);

    sort(s, s+n);
    sort(b, b+m);

    if (s[0] < b[m-1]) {
        stock = r/s[0];
        r %= s[0];
        r += stock * b[m-1];
    }
    printf("%d", r);
}