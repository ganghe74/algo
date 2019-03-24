#include <iostream>
using namespace std;
int main() {
    int i=63;
    long long num;
    scanf("%lld", &num);
    while (!((num>>i)&1)) i--;
    for (;i>=0;--i) printf("%d", (num>>i)&1);
}