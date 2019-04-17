#include <iostream>
using namespace std;
int a[10000];
int main() {
    int N, M, num, l = 0, sum = 0, cnt = 0;
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    for (int i=0;i<N;++i) {
        sum += a[i];
        while (sum > M) sum -= a[l++];
        if (sum == M) cnt++;
    }
    printf("%d", cnt);
}