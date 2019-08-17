#include <bits/stdc++.h>
using namespace std;
bool a[100][100];
int main() {
    int x1, x2, y1, y2;
    for (int i=0;i<4;++i) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int x=x1;x<x2;++x) {
            for (int y=y1;y<y2;++y) a[x][y] = 1;
        }
    }
    int cnt = 0;
    for (int i=0;i<100;++i) {
        for (int j=0;j<100;++j) {
            if (a[i][j]) cnt++;
        }
    }
    printf("%d", cnt);
}