#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, A, B, C, D;
    scanf("%d%d%d%d%d", &L, &A ,&B, &C, &D);
    printf("%d", max(0, L - max((A+C-1)/C, (B+D-1)/D)));
}