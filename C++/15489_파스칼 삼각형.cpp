#include <iostream>
using namespace std;
int main() {
    int a[31][31] = {0};
    a[1][1] = 1;
    for (int i=2;i<=30;++i) {
        a[i][1] = 1;
        a[i][i] = 1;
        for (int j=2;j<i;++j) a[i][j] = a[i-1][j-1] +a[i-1][j];
    }
    int R, C, W, sum = 0;
    cin >> R >> C >> W;
    for (int i=0;i<W;++i) {
        for (int j=0;j<=i;++j) sum += a[R+i][C+j];
    }
    cout << sum;
}