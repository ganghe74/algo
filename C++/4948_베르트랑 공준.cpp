#include <iostream>
using namespace std;
int main() {
    bool prime[246913] = {1,1};
    for (int i=2;i<246913;++i) {
        if (!prime[i]) {
            for (int j=2;j*i<246913;++j) {
                prime[i*j] = 1;
            }
        }
    }
    int N;
    scanf("%d", &N);
    while (N != 0) {
        int count = 0;
        for (int i=N+1;i<= 2*N;++i) {
            if (!prime[i]) count += 1;
        }
        printf("%d\n", count);
        scanf("%d", &N);
    }
}