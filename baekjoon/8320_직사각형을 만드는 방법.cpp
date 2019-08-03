#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i=1;i*i<=n;++i) {
        for (int j=i;i*j<=n;++j) cnt++;
    }
    printf("%d", cnt);
}