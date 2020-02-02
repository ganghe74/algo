#include <bits/stdc++.h>
using namespace std;
bool c[250001];
int N, cnt;
int main() {
    scanf("%d", &N);
    for (int i=1;i<=500;++i) {
        for (int j=1;j<i;++j) {
            if (i*i - j*j == N) cnt++;
        }
    }
    printf("%d", cnt);
}
