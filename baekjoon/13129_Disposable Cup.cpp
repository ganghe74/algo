#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, N;
    scanf("%d%d%d", &A, &B, &N);
    for (int i=1;i<=N;++i) printf("%d ", A*N+B*i);
}