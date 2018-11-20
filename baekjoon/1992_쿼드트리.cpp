#include <bits/stdc++.h>
using namespace std;

int N;
int picture[64][64];

void zip(int y, int x, int size) {
    bool zipable = true;
    int first = picture[y][x];
    for (int i=y;i<y+size;++i) {
        for (int j=x;j<x+size;++j) {
            if (picture[i][j] != first) zipable = false;
        }
    }
    if (zipable) printf("%d", first);
    else {
        printf("(");
        zip(y, x, size/2);
        zip(y, x+size/2, size/2);
        zip(y+size/2, x, size/2);
        zip(y+size/2, x+size/2, size/2);
        printf(")");
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf("%1d", &picture[i][j]);
    }
    zip(0,0,N);
}