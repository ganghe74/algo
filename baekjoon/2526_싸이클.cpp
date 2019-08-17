#include <bits/stdc++.h>
using namespace std;
int a[101];
int main() {
    int N, P;
    scanf("%d%d", &N, &P);
    int n = N*N%P;
    while (!a[n*N%P]) {
        a[n*N%P] = a[n] + 1;
        n = n*N%P;
    }
    printf("%d", a[n] - a[n*N%P]+1);
}