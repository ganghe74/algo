#include <iostream>
using namespace std;
bool a[10001];
int main() {
    int N, x, y, ans = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &x, &y);
        for (int i=x;i<y;++i) a[i] = true;
    }
    for (int i=0;i<=10000;++i)
        if (a[i]) ans++;
    printf("%d", ans);
}