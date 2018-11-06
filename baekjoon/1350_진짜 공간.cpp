#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    int files[N];
    for (int i=0;i<N;++i) {
        scanf("%d", &files[i]);
    }
    int cluster;
    scanf("%d", &cluster);
    long long answer = 0;
    for (int i=0;i<N;++i) {
        if (files[i] == 0) continue;
        answer += ((files[i]-1)/cluster+1) * cluster;
    }
    printf("%lld", answer);
}