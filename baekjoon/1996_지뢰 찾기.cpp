#include <bits/stdc++.h>
using namespace std;
int a[1002][1002];
int cnt(int r, int c) {
    int sum = 0;
    for (int i=r-1;i<=r+1;++i) {
        for (int j=c-1;j<=c+1;++j) sum += a[i][j];
    }
    return sum - a[r][c];
}
int main() {
    int N;
    char c;
    scanf("%d", &N);
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            scanf(" %c", &c);
            if (isdigit(c)) a[i][j] = c - '0';
        }
    }
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) {
            if (a[i][j] > 0) printf("*");
            else {
                int mine = cnt(i,j);
                if (mine >= 10) printf("M");
                else printf("%d", mine);
            }
        }
        puts("");
    }
}