#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, cnt = 0, i = 1;
    scanf("%d", &N);
    while (i*i < N) {
        if (N % i == 0) cnt += 2;
        ++i;
    }
    if (i*i == N) cnt++;
    printf("%d", cnt);
}