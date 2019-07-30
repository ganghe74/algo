#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, K;
    scanf("%d%d", &C, &K);
    int q = C % (int)pow(10, K);
    if (q >= pow(10, K) / 2) C += pow(10, K);
    printf("%d", C - q);
}