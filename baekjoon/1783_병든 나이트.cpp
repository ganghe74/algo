#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    if (N == 1) printf("1");
    else if (N == 2) {
        printf("%d", min((M+1)/2,4));
    }
    else {
        if (M < 7) printf("%d", min(M, 4));
        else printf("%d", M-2);
    }
}