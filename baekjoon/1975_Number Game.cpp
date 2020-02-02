#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        int cnt = 0;
        scanf("%d", &N);
        for (int i=2;i<=N;++i)
            for (int j=i;N % j == 0;j*=i) cnt++;
        printf("%d\n", cnt);
    }
}
