#include <iostream>
using namespace std;
int main() {
    int a[100001];
    int N, K, sum = 0, max = 0x80000000;
    scanf("%d %d", &N, &K);
    for (int i=0;i<K-1;++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i=K-1;i<N;++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        if (max < sum) max = sum;
        sum -= a[i-K+1];
    }
    printf("%d", max);
}