#include <bits/stdc++.h>
using namespace std;

int N, M, r, c, K, op, a[20][20];
int dice[6];
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

bool move(int num) {
    num--;
    int nr = r + dr[num];
    int nc = c + dc[num];
    if (!(0 <= nr && nr < N && 0 <= nc && nc < M)) return false;
    r = nr; c = nc;
    if (num == 0) {
        int tmp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = dice[5];
        dice[5] = tmp;
    }
    else if (num == 1) {
        int tmp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = dice[2];
        dice[2] = tmp;
    }
    else if (num == 2) {
        int tmp = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[4];
        dice[4] = dice[2];
        dice[2] = tmp;
    }
    else {
        int tmp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[4];
        dice[4] = dice[5];
        dice[5] = tmp;
    }
    if (a[r][c] == 0) a[r][c] = dice[2];
    else {
        dice[2] = a[r][c];
        a[r][c] = 0;
    }
    return true;
}

int main() {
    scanf("%d%d%d%d%d", &N, &M, &r, &c, &K);
    for (int i=0;i<N;++i)
        for (int j=0;j<M;++j) scanf("%d", &a[i][j]);
    while (K--) {
        scanf("%d", &op);
        if (move(op)) printf("%d\n", dice[5]);
    }
}