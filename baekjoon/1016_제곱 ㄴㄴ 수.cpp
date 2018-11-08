#include <iostream>
using namespace std;
bool prime[1000001];
int main() {
    long long min, max;
    scanf("%lld %lld", &min, &max);
    bool d[max-min+1] = {0};
    for (long long i=2;i<1000001;++i) {
        if (!prime[i]) {
            for (int j=2;i*j<1000001;++j) prime[i*j] = 1;
            long long start;
            if (min%(i*i) == 0) start = min;
            else start = (min / (i*i) + 1) *i*i;
            for (long long j=start;j<=max;j+=i*i) {
                d[j-min] = 1;
            }
        }
    }

    int answer = 0;
    for (int i=0;i<=max-min;++i) {
        if (!d[i]) answer += 1;
    }
    printf("%d", answer);
}