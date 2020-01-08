#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B, C, D;
    scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);
    printf("%d", min((N+A-1) / A * B, (N+C-1) / C * D));
}