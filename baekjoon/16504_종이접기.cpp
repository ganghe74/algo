#include <iostream>
using namespace std;
int main() {
    long long sum = 0;
    int n, temp;
    scanf("%d", &n);
    for (int i=0;i<n*n;++i) {
        scanf("%d", &temp);
        sum += temp;
    }
    printf("%lld", sum);
}