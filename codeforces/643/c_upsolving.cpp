#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    int A, B, C, D;
    scanf("%d%d%d%d", &A, &B, &C, &D);
    
    lint ans = 0;
    for (int s=A+B;s<=B+C;++s) {
        int k = s - A-B;
        int a = min(B-A, k);
        int b = min(C-B, k);
        int numofs = a-(k-b)+1;
        int numofz = max(0, min(D, s-1) - C + 1);
        ans += 1LL * numofs * numofz;
    }
    printf("%lld", ans);
}
