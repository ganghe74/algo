#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y=0, M=0;
    scanf("%d", &N);
    while (N--) {
        int t;
        scanf("%d", &t);
        Y += ((t + 30) / 30) * 10;
        M += ((t + 60) / 60) * 15;
    }
    if (Y <= M) printf("Y ");
    if (M <= Y) printf("M ");
    printf("%d", min(Y, M));
}