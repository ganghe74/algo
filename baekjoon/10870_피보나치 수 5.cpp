#include <iostream>
using namespace std;
int main() {
    int fibo[21] = {0,1};
    for (int i=2;i<=20;++i) fibo[i] = fibo[i-1] + fibo[i-2];
    int n;
    scanf("%d", &n);
    printf("%d", fibo[n]);
}