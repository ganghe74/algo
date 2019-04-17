#include <iostream>
using namespace std;
int main() {
    long long d[120] = {0,1,1,1};
    for (int i=4;i<=116;++i) d[i] = d[i-1] + d[i-3]; 
    int n;
    scanf("%d", &n);
    printf("%lld", d[n]);
}