#include <bits/stdc++.h>
using namespace std;
int N, cnt;
int main() {
    scanf("%d", &N);
    for (int i=3;i<=N;++i)
        for (int j=i;j>0;j/=10) cnt += (j % 10 == 3 || j % 10 == 6 || j % 10 == 9);
    printf("%d", cnt);
}
