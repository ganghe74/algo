#include <iostream>
using namespace std;
int d[1000001] = {1,1};
int main() {
    for (int i=2;i<=1000000;++i) {
        d[i] = (d[i-1] + d[i-2]) % 15746;
    }
    int N;
    scanf("%d", &N);
    printf("%d", d[N]);
}