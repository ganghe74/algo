#include <bits/stdc++.h>
using namespace std;
int main() {
    int L, A, pos;
    char dir;
    while (scanf("%d%d", &L, &A) != EOF) {
        int cntl = 0, M = -1, start[A];
        bool two = false, left = true;
        for (int i=0;i<A;++i) {
            scanf("%d %c", &pos, &dir);
            start[i] = pos;
            if (dir == 'L') {
                cntl++;
                if (M == pos) two = true;
                if (M < pos) {
                    M = pos;
                    left = true;
                    two = false;
                }
            }
            else {
                if (M == L - pos) two = true;
                if (M < L - pos) {
                    M = L - pos;
                    left = false;
                    two = false;
                }
            }
        }
        sort(start, start+A);
        printf("The last ant will fall down in %d seconds - ", M);
        if (two) printf("started at %d and %d.\n", start[cntl-1], start[cntl]);
        else {
            if (left) printf("started at %d.\n", start[cntl-1]);
            else printf("started at %d.\n", start[cntl]);
        }
    }
}