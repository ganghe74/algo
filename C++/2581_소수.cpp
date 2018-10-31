#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    bool prime[10001] = {1,1};
    for (int i=2;i<10001;++i) {
        if (!prime[i]) {
            for (int j=2;j*i<10001;++j) {
                prime[i*j] = 1;
            }
        }
    }
    
    int M, N;
    vector<int> primes;
    scanf("%d", &M);
    scanf("%d", &N);
    for (int i=M;i<=N;++i) {
        if (!prime[i]) primes.push_back(i);
    }
    if (primes.empty()) printf("-1");
    else {
        int sum = 0;
        for (auto n : primes) sum += n;
        printf("%d\n%d", sum, primes[0]);
    }
}