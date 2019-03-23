#include <iostream>
using namespace std;
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i=3;i<=n;++i) ans += i * (i-1);
    printf("%d", ans);
}