#include <iostream>
#include <cstring>
using namespace std;
int n,m;
bool areFreinds[10][10];

int countPairings(bool taken[10], int start) {
    bool finished = true;
    for (int i=0;i<n;++i) if (!taken[i]) finished = false;
    if (finished) return 1;
    int cnt = 0;
    for (int i=start;i<n;++i) {
        for (int j=start;j<i;++j) {
            if (!taken[i] && !taken[j] && areFreinds[i][j]) {
                taken[i] = taken[j] = true;
                cnt += countPairings(taken, j);
                taken[i] = taken[j] = false;
            }
        }
    }
    return cnt;
}

int main() {
    int C;
    scanf("%d", &C);
    while(C--) {
        scanf("%d %d", &n, &m);
        for (int i=0;i<m;++i) {
            int in[2];
            scanf("%d %d", &in[0], &in[1]);
            areFreinds[in[0]][in[1]] = true;
            areFreinds[in[1]][in[0]] = true;
        }
        bool temp[10] = {0};
        printf("%d\n", countPairings(temp, 0));
        memset(areFreinds, 0, sizeof(areFreinds));
    }
}