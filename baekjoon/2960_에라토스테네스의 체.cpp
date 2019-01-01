#include <iostream>
using namespace std;
bool prime[1001];
int main() {
    int N, K, cnt = 0;
    scanf("%d%d", &N, &K);
    for (int i=2;i<=N;++i) {
        if (!prime[i]) {
            for (int j=1;j*i<=N;++j) {
                if (!prime[i*j]) {
                    ++cnt;
                    if (cnt == K) {
                        printf("%d", i*j);
                        break;
                    }
                    prime[i*j] = true;
                }
            }
        }
        if (cnt == K) {
            break;
        }
    }
}