#include <iostream>
#define min(a, b) (a<b?a:b)
using namespace std;
int a[1000][3];
int d[1000][3];
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    }
    for (int i=0;i<=2;++i) d[0][i] = a[0][i];
    for (int i=1;i<N;++i) {
        d[i][0] = a[i][0] + min(d[i-1][1], d[i-1][2]);
        d[i][1] = a[i][1] + min(d[i-1][0], d[i-1][2]);
        d[i][2] = a[i][2] + min(d[i-1][0], d[i-1][1]);
    }
    int answer = min(d[N-1][0], d[N-1][1]);
    answer = min(answer, d[N-1][2]);
    printf("%d", answer);
}