#include <iostream>
using namespace std;
int main() {
    int T, num;
    int start[2], end[2];
    scanf("%d", &T);
    while (T--) {
        int cnt = 0;
        scanf("%d%d%d%d", &start[0], &start[1], &end[0], &end[1]);
        scanf("%d", &num);
        while (num--) {
            int x, y, r;
            scanf("%d%d%d", &x, &y, &r);
            int d_start = (x-start[0])*(x-start[0]) + (y-start[1]) * (y-start[1]);
            int d_end = (x-end[0])*(x-end[0]) + (y-end[1])*(y-end[1]);
            if (d_start < r*r && d_end < r*r) continue;
            else if (d_start < r*r || d_end < r*r) ++cnt;
        }
        printf("%d\n", cnt);
    }
}