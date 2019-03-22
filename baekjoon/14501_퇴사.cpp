#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    int T[N], P[N], D[N] = {0};
    for (int i=0;i<N;++i) {
        scanf("%d", &T[i]);
        scanf("%d", &P[i]);
    }
    for (int i=0;i<N;++i) {
        int m = 0;
        for (int j=0;j<i;++j) m = max(m, D[j]);
        for (int j=i+T[i]-1;j<N;++j) D[j] = max(D[j], m+P[i]);
    }
    for (int i=0;i<N;++i) printf("%d ", D[i]);
    puts("");
    printf("%d", D[N-1]);
}