#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    int d[N][3] = {{1,1,1}};
    for (int i=1;i<N;++i) {
        d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % 9901;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % 9901;
        d[i][2] = (d[i-1][0] + d[i-1][1]) % 9901;
    }
    printf("%d", (d[N-1][0] + d[N-1][1] + d[N-1][2]) % 9901);
}