#include <iostream>
using namespace std;

int N, ans;
char a[50][50];

int get() {
    int cnt, ret = 0;
    for (int i=0;i<N;++i) {
        cnt = 1;
        for (int j=0;j<N-1;++j) {
            if (a[i][j] == a[i][j+1]) cnt++;
            else cnt = 1;
            ret = max(ret, cnt);
        }
        cnt = 1;
        for (int j=0;j<N-1;++j) {
            if (a[j][i] == a[j+1][i]) cnt++;
            else cnt = 1;
            ret = max(ret, cnt);
        }
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) scanf(" %c", &a[i][j]);
    }
    for (int i=0;i<N;++i) {
        for (int j=0;j<N-1;++j) {
            swap(a[i][j], a[i][j+1]);
            ans = max(ans, get());
            swap(a[i][j], a[i][j+1]);
            swap(a[j][i], a[j+1][i]);
            ans = max(ans, get());
            swap(a[j][i], a[j+1][i]);
        }
    }
    printf("%d", ans);
}