#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[1000];
    int N, L, ans = 0;
    scanf("%d%d", &N, &L);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a, a+N);
    for (int i=0;i<N;) {
        int tape = a[i] + L;
        while (a[i] < tape && i < N) i++;
        ans++;
    }
    printf("%d", ans);
}