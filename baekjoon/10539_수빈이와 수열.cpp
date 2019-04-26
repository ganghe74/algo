#include <iostream>
using namespace std;
long long a[101];
int main() {
    int N;
    scanf("%d", &N);
    for (int i=1;i<=N;++i) scanf("%lld", &a[i]);
    for (int i=1;i<=N;++i) {
        printf("%lld ", a[i]*i - a[i-1]*(i-1));
    }
}