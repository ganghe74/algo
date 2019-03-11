#include <iostream>
using namespace std;
int a[101][101];
int cover(int x, int y) {
    int ret = 0;
    for (int i=y;i<y+10;++i) {
        for (int j=x;j<x+10;++j) {
            if (!a[i][j]) {
                a[i][j] = 1;
                ret++;
            }
        }
    }
    return ret;
}
int main() {
    int N, x, y, ans = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &x, &y);
        ans += cover(x, y);
    }
    printf("%d", ans);
}