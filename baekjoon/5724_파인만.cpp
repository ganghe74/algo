#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (true) {
        scanf("%d", &N);
        if (N == 0) break;
        int cnt = 0;
        for (int i=1;i<=N;++i) {
            cnt += (N-i+1)*(N-i+1);
        }
        printf("%d\n", cnt);
    }
}