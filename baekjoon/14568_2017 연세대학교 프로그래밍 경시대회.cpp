#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, ans = 0;
    scanf("%d", &N);
    for (int A=2;A<N;A+=2) ans += max(0, (N - A) / 2 - 1);
    printf("%d", ans);
}