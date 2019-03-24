#include <iostream>
using namespace std;
int main() {
    int a[45];
    for (int i=0;i<45;++i) a[i] = i * (i+1) / 2;
    int T, K;
    scanf("%d", &T);
    while (T--) {
        bool ok = false;
        scanf("%d", &K);
        for (int i=1;i<45;++i) {
            for (int j=i;j<45;++j) {
                for (int k=j;k<45;++k) {
                    if (a[i] + a[j] + a[k] == K) ok = true;
                    if (ok) break;
                }
                if (ok) break;
            }
            if (ok) break;
        }
        printf("%d\n", ok);
    }
}