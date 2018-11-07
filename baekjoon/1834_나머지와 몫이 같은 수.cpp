#include <iostream>
using namespace std;
int main() {
    long long N, answer = 0;
    scanf("%lld", &N);
    answer = (N*N*N - N) / 2;
    printf("%lld", answer);
}