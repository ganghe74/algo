#include <iostream>
#include <queue>
using namespace std;
long long next(long long prev) {
    return (prev * 214013 + 2531011) % 4294967296;
}
int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        int K, N, sum = 0, ans = 0;
        long long num = 1983;
        queue<int> Q;
        scanf("%d%d", &K, &N);
        while (N--) {
            int sig = num % 10000 + 1;
            num = next(num);
            sum += sig;
            Q.push(sig);
            while (sum > K) {
                sum -= Q.front();
                Q.pop();
            }
            if (sum == K) ans++;
        }          
        printf("%d\n", ans);
    }
}