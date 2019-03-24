#include <iostream>
using namespace std;
int main() {
    char s[51];
    int L;
    long long ans = 0;
    scanf("%d\n%s", &L, s);
    for (int i=L-1;i>=0;--i) {
        ans = (ans * 31 + (s[i] - 'a' + 1)) % 1234567891;
    }
    printf("%lld\n", ans);
}