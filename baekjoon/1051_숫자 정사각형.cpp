#include <iostream>
using namespace std;
int main() {
    int a[50][50];
    int N, M, ans = 1;
    scanf("%d%d", &N, &M);
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) scanf("%1d", &a[i][j]);
    }
    for (int i=0;i<N;++i) {
        for (int j=0;j<M;++j) {
            int size = 1, mv = 1;
            while (i + mv < N && j + mv < M) {
                if (a[i][j] == a[i][j+mv] && a[i][j] == a[i+mv][j] && a[i][j] == a[i+mv][j+mv]) {
                    size = (mv+1)*(mv+1);
                }
                mv++;
            }
            ans = max(ans, size);
        }
    }
    printf("%d", ans);
}