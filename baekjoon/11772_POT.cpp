#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, P, X = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &P);
        X += pow(P/10, P%10);
    }
    printf("%d", X);
}