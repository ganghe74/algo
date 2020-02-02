#include <bits/stdc++.h>
using namespace std;
int N, cnt;
int main() {
    scanf("%d", &N);
    for (int i=1;i<=N;++i) {
        int s = 0;
        for (int j=i;j>0;j/=10) s += j % 10;
        if (i % s == 0) cnt++;
    }
    printf("%d", cnt);
}
