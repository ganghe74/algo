#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, cnt = 0;
        scanf("%d", &N);
        for (int k=5;k<=N;k*=5) {
            cnt += N / k;
        }
        printf("%d\n", cnt);
    }
}