#include <iostream>
using namespace std;
int count[3];
int a[3000][3000];
bool same(int x, int y, int n) {
    for (int i=x;i<x+n;++i) {
        for (int j=y;j<y+n;++j) {
            if (a[x][y] != a[i][j]) return false;
        }
    }
    return true;
}
void solve(int x, int y, int n) {
    if (same(x,y,n)) {
        count[a[x][y]+1] += 1;
        return;
    }
    int m = n/3;
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            solve(x+i*m,y+j*m,m);
        }
    }
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%d", &a[i][j]);
    }
    solve(0,0,N);
    for (int i=0;i<3;++i) printf("%d\n", count[i]);
}