#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x, cnt = 0;
    scanf("%d", &N);
    for (int i=1;i<=N;++i) {
        scanf("%d", &x);
        if (i != x) cnt++;
    }
    printf("%d", cnt);
}