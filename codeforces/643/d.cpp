#include <bits/stdc++.h>
using namespace std;

int n, s;

int main() {
    scanf("%d%d", &n, &s);
    if (s < n*2) {
        puts("NO");
        return 0;
    }
    puts("YES");
    printf("%d ", 2 + s-n*2);
    for (int i=1;i<n;++i) printf("2 ");
    puts("");
    puts("1");
}
