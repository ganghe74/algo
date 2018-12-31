#include <iostream>
#define min(a,b) ((a)<(b))?(a):(b)
using namespace std;
bool a[51][51];
int check(int r, int c) {
    int cnt = 0;
    bool color = 0;
    for (int i=r;i<r+8;++i) {
        for (int j=c;j<c+8;++j) {
            if (a[i][j] != color) {
                cnt++;
            }
            color = !color;
        }
        color = !color;
    }
    return min(cnt, 64-cnt);
}
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            char x;
            scanf("\n%c", &x);
            if (x == 'W') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    int answer = check(0,0);
    for (int i=0;i<=N-8;++i) {
        for (int j=0;j<=M-8;++j) {
            int temp = check(i, j);
            if (temp < answer) answer = temp;
        }
    }
    printf("%d", answer);
}