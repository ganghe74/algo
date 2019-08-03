#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, K, candy;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);
        int cnt = 0;
        while (N--) {
            scanf("%d", &candy);
            cnt += candy / K;
        }
        printf("%d\n", cnt);
    }
}