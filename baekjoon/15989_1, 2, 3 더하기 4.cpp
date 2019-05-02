#include <iostream>
using namespace std;

int d[10001][3];

int main() {
    d[1][0] = 1; 
    d[2][0] = 1;
    d[2][1] = 1;
    d[3][0] = 1;
    d[3][1] = 1;
    d[3][2] = 1;
    for (int i=4;i<=10000;++i) {
        d[i][0] = d[i-1][0];
        d[i][1] = d[i-2][1] + d[i-2][0];
        d[i][2] = d[i-3][2] + d[i-3][1] + d[i-3][0];
    }
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", d[n][0] + d[n][1] + d[n][2]);
    }
}