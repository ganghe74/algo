#include <iostream>
using namespace std;
int a[50][2];
int d[50];
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;++i) {
        scanf("%d%d", &a[i][0], &a[i][1]);
    }
    for (int i=0;i<N;++i) {
        int cnt = 0;
        for (int j=0;j<N;++j) {
            if (a[i][0] < a[j][0] && a[i][1] < a[j][1]) cnt++;
        }
        d[i] = cnt + 1;
    }
    for (int i=0;i<N;++i) printf("%d ", d[i]);
}