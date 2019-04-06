#include <iostream>
using namespace std;
int main() {
    int T, N;
    char a[100001], b[100001];
    scanf("%d", &T);
    while (T--) {
        int W1 = 0, W2 = 0, diff = 0, ans = 0;
        scanf("%d ", &N);
        scanf("%s %s", a, b);
        for (int i=0;i<N;++i) {
            if (a[i] != b[i]) diff++;
            if (a[i] == 'W') W1++;
            if (b[i] == 'W') W2++;
        }
        while (W1 < W2) {
            W1++;
            diff--;
            ans++;
        }
        while (W1 > W2) {
            W1--;
            diff--;
            ans++;
        }
        while (diff > 0) {
            diff -= 2;
            ans++;
        }
        printf("%d\n", ans);
    }
}