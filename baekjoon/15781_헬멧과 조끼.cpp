#include <iostream>
using namespace std;
int main() {
    int N, M, num, maxi, ans = 0;
    scanf("%d%d", &N, &M);
    maxi = 0;
    for (int i=0;i<N;++i) {
        scanf("%d", &num);
        maxi = max(maxi, num);
    }
    ans += maxi;
    maxi = 0;
    for (int i=0;i<M;++i) {
        scanf("%d", &num);
        maxi = max(maxi, num);
    }
    ans += maxi;
    printf("%d", ans);
}