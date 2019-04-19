#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];
int main() {
    int N, ans = 0;
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    sort(a, a+N, greater<int>());
    for (int i=0;i<N;++i) {
        ans = max(ans, a[i] + i + 1);
    }
    printf("%d", ans + 1);
}