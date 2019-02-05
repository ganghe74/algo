#include <iostream>
#include <queue>
using namespace std;
struct RNG {
    unsigned seed;
    RNG() : seed(1983) {}
    unsigned next() {
        unsigned ret = seed;
        seed = ((seed * 214013u) + 2531011u);
        return ret % 10000 + 1;
    }
};
int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        int K, N, sum = 0, ans = 0;
        RNG rng;
        queue<int> Q;
        scanf("%d%d", &K, &N);
        while (N--) {
            int sig = rng.next();
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