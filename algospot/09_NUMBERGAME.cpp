#include <bits/stdc++.h>
using namespace std;

const int EMPTY = -987654321;
int tc, n, board[50], d[50][50];

int play(int left, int right) {
    if (left > right) return 0;
    int &ret = d[left][right];
    if (ret != EMPTY) return ret;
    ret = max(board[left] - play(left+1, right), board[right] - play(left, right-1));
    if (right - left + 1 >= 2) {
        ret = max(ret, -play(left + 2, right));
        ret = max(ret, -play(left, right - 2));
    }
    return ret;
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i=0;i<n;++i)
            scanf("%d", &board[i]);
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                d[i][j] = EMPTY;
        printf("%d\n", play(0, n-1));
    }
}
