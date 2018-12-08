#include <iostream>
using namespace std;
int main() {
    int C, K, P;
    scanf("%d%d%d", &C, &K, &P);
    int answer = 0;
    for (int i=1;i<=C;++i) {
        answer += K*i + P*i*i;
    }
    printf("%d", answer);
}