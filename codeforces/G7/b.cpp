#include <bits/stdc++.h>
using namespace std;

int n, b, m;
int main() {
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        scanf("%d", &b);
        printf("%d ", b+m);
        m = max(m, b+m);
    }
}
