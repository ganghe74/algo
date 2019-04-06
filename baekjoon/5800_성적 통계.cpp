#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[50];
    int K, N, gap;
    scanf("%d", &K);
    for (int i=1;i<=K;++i) {
        gap = 0;
        scanf("%d", &N);
        for (int j=0;j<N;++j) scanf("%d", &a[j]);
        sort(a, a+N);
        for (int j=1;j<N;++j) gap = max(gap, a[j]-a[j-1]);
        printf("Class %d\n", i);
        printf("Max %d, Min %d, Largest gap %d\n", a[N-1], a[0], gap);
    }
}