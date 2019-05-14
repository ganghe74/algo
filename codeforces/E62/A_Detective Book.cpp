#include <iostream>
using namespace std;
int a[10001];
int main() {
    int n, i, day = 0;
    scanf("%d", &n);
    for (i=1;i<=n;++i) scanf("%d", &a[i]);
    int now_page = 1, max_page = 0;
    while (now_page <= n) {
        max_page = max(max_page, a[now_page]);
        if (max_page <= now_page) day++;
        now_page++;
    }
    printf("%d", day);
}