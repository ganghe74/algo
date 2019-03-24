#include <iostream>
using namespace std;

int go(int N) {
    int sum = N;
    while (N > 0) {
        sum += N % 10;
        N /= 10;
    }
    return sum;
}

int main() {
    int N, ans = 1;
    scanf("%d", &N);
    while (go(ans) != N && ans < 1000000) {
        ans++;
    }
    if (ans == 1000000) ans = 0;
    printf("%d", ans);
}