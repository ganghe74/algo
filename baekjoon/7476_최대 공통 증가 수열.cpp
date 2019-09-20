#include <bits/stdc++.h>
using namespace std;

int N, M, a[500], b[500], d[500][500], path[500][500];

int LCIS(int aPos, int bPos) {
    int &ret = d[aPos][bPos];
    if (ret) return ret;
    ret = 1;
    for (int i=aPos+1;i<N;++i) {
        if (a[aPos] >= a[i]) continue;
        for (int j=bPos+1;j<M;++j) {
            if (a[i] == b[j]) {
                int tmp = LCIS(i, j) + 1;
                if (tmp > ret) {
                    ret = tmp;
                    path[aPos][bPos] = i*1000 + j;
                }
                break;
            }
        }
    }
    return ret;
}

void print_path(int aPos, int bPos) {
    printf("%d ", a[aPos]);
    if (path[aPos][bPos]) print_path(path[aPos][bPos] / 1000, path[aPos][bPos] % 1000);
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) scanf("%d", &a[i]);
    scanf("%d", &M);
    for (int i=0;i<M;++i) scanf("%d", &b[i]);
    int Max = 0, Maxpos = 0;
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            if (a[i] == b[j]) {
                int tmp = LCIS(i, j);
                if (tmp > Max) {
                    Max = tmp;
                    Maxpos = 1000*i + j;
                }
            }
        }
    }
    printf("%d\n", Max);
    print_path(Maxpos / 1000, Maxpos % 1000);
}