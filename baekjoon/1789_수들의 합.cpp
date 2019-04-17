#include <iostream>
using namespace std;
int main() {
    long long S, ans = 0;
    scanf("%lld", &S);
    while (S >= ans*(ans+1)/2) ans++;
    printf("%lld", ans-1);
}