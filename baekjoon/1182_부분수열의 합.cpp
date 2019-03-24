#include <iostream>
using namespace std;
int N, S, ans;
int a[20];
void go(int now, int x) {
    if (now == N) {
        if (x == S) ans++;
        return;
    }
    go(now+1, x+a[now]);
    go(now+1, x);
    return;
}
int main() {
    scanf("%d%d", &N, &S);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    go(0, 0);
    if (S == 0) ans--;
    printf("%d", ans);
}