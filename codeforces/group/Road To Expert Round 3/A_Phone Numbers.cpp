#include <iostream>
using namespace std;
int main() {
    int cnt = 0, cnt8 = 0;
    int n, tmp;
    scanf("%d", &n);
    for (int i=0;i<n;++i) {
        scanf("%1d", &tmp);
        if (tmp == 8) cnt8++;
        cnt++;
    }
    int ans = 0;
    while (cnt8 > 0 && cnt >= 11) {
        cnt8--;
        cnt -= 11;
        ans++;
    }
    printf("%d", ans);
}